#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <llvm/Linker.h>
#include <llvm/PassManager.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_os_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/Host.h>
#include <llvm/Target/TargetOptions.h>
#include "ecma/compiler/helper/type.h"
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/output/phase.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::frontend;
using namespace ecma::frontend::output;

static std::string temp_filename()
{
    char *filename = strdup((char *)"/tmp/ecma_XXXXXXXX");
    mktemp(filename); //TODO: Replace with a better way (warning at compile-time.)
    return std::string(filename);
}

Phase::Result Output::run(Args &args, std::vector<std::unique_ptr<Unit>> &units)
{
    bool executable = !(*args.compileOnly || *args.llvmOutput);
    bool success = true;
    std::string output;

    if (units.size() > 1 && !args.output->empty() && !executable)
    {
        std::cerr << "Cannot specify -o when generating multiple files." << std::endl;
        return Phase::Result::ERROR;
    }
    output = *args.output;

    // Init LLVM
    llvm::InitializeNativeTarget();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmPrinters();
    llvm::InitializeAllAsmParsers();

    std::string errorMsg;
    target = llvm::TargetRegistry::lookupTarget(llvm::sys::getDefaultTargetTriple(), errorMsg);

    if (!target)
    {
        std::cerr << "LLVM error: " << errorMsg << std::endl;
        return Phase::Result::ERROR;
    }

    llvm::TargetOptions targetOptions;
    targetMachine.reset(target->createTargetMachine(llvm::sys::getDefaultTargetTriple(), llvm::sys::getHostCPUName(), "", targetOptions));

    // Output units
    for (auto it = units.begin(); it != units.end(); ++it)
    {
        auto module = (*it)->take_llvm_module();
        passModule(module);

        if (!executable)
        {
            std::string output_path = output;

            if (args.output->empty())
            {
                output_path = (*it)->source().name();
                if (output_path != "-")
                {
                    if (*args.compileOnly && *args.llvmOutput)
                    {
                        output_path += EXT_LLVM;
                    }
                    else if (*args.compileOnly)
                    {
                        output_path += EXT_ASM;
                    }
                    else if (*args.llvmOutput)
                    {
                        output_path += EXT_LLVM_BC;
                    }
                }
            }

            bool asmOutput = *args.compileOnly;
            bool llvmOutput = *args.llvmOutput;

            bool outputResult;
            if (output_path == "-")
            {
                llvm::raw_os_ostream os(std::cout);
                llvm::formatted_raw_ostream out(os);
                outputResult = outputModule(module, out, asmOutput, llvmOutput);
            }
            else
            {
                llvm::tool_output_file outputFile(output_path.c_str(), errorMsg);
                if (!errorMsg.empty())
                {
                    std::cerr << errorMsg << std::endl;
                    success = false;
                    continue;
                }
                llvm::formatted_raw_ostream out(outputFile.os());
                outputResult = outputModule(module, out, asmOutput, llvmOutput);
                outputFile.keep();
            }

            success = success && outputResult;
        }

        (*it)->llvm_module(module);
    }

    if (executable)
    {
        if (args.output->empty())
        {
            output = "a.out";
        }

        bool debug = args.hasCompilerFlag("output-debug") || args.hasCompilerFlag("debug");
        success = success && outputExecutable(output, units, debug);
    }

    if (utils::Messages::HasErrors() || !success)
    {
        return Phase::Result::ERROR;
    }

    return Phase::Result::CONTINUE;
}

bool Output::outputModule(llvm::Module *module, llvm::formatted_raw_ostream &out, bool asmOutput, bool llvmOutput)
{
    llvm::PassManager passManager;

    if (!llvmOutput && (asmOutput))
    {
        auto outputType = llvm::TargetMachine::CGFT_Null;

        if (asmOutput)
        {
            outputType = llvm::TargetMachine::CGFT_AssemblyFile;
        }

        targetMachine->addPassesToEmitFile(passManager, out, outputType);
    }

    passManager.run(*module);

    if (asmOutput && llvmOutput)
    {
        out << *module;
    }

    return true;
}

static void createMain(llvm::LLVMContext &context, llvm::Module *module, std::vector<std::unique_ptr<Unit>> &units)
{
    llvm::Function *mainFunction = llvm::Function::Create(compiler::helper::type<int (int, char **)>(context), llvm::GlobalVariable::ExternalLinkage, "main", module);

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");
    mainFunction->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(context);
    irBuilder.SetInsertPoint(entryBlock);

    irBuilder.CreateRet(llvm::ConstantInt::get(compiler::helper::type<int>(context), 0));
}

bool Output::outputExecutable(const std::string &output_path, std::vector<std::unique_ptr<Unit>> &units, bool debug)
{
    llvm::LLVMContext context;
    llvm::Module module(output_path, context);

    llvm::Linker ld(&module);
    for (auto it = units.begin(); it != units.end(); ++it)
    {
        auto unitModule = (*it)->take_llvm_module();

        std::string errorMsg;
        if (ld.linkInModule(unitModule, llvm::Linker::PreserveSource, &errorMsg))
        {
            std::cerr << errorMsg << std::endl;
            return false;
        }

        (*it)->llvm_module(unitModule);
    }

    createMain(context, &module, units);

    passModule(&module);

    if (debug)
    {
        std::string debug_path = output_path + ".debug.ll";
        std::string errorMsg;
        llvm::tool_output_file outputFile(debug_path.c_str(), errorMsg);
        outputFile.keep();
        if (!errorMsg.empty())
        {
            std::cerr << errorMsg << std::endl;
        }
        else
        {
            llvm::formatted_raw_ostream out(outputFile.os());
            outputModule(&module, out, true, true);
        }
    }

    std::string objectPath = temp_filename() + ".o";
    std::string errorMsg;
    llvm::tool_output_file objectFile(objectPath.c_str(), errorMsg);
    if (!errorMsg.empty())
    {
        std::cerr << errorMsg << std::endl;
        return false;
    }
    llvm::formatted_raw_ostream out(objectFile.os());

    llvm::PassManager passManager;
    targetMachine->addPassesToEmitFile(passManager, out, llvm::TargetMachine::CGFT_ObjectFile);
    passManager.run(module);

    out.flush();

#if defined(WIN32) || defined(_WIN32)
    #error "Platform not supported yet."
#else
    std::string command = "gcc -o " + output_path + " " + objectPath;
#endif

    if (system(command.c_str()) == -1)
    {
        return false;
    }

    return true;
}

bool Output::passModule(llvm::Module *module)
{
    llvm::PassManager passManager;

    module->setTargetTriple(targetMachine->getTargetTriple());
    module->setDataLayout(targetMachine->getDataLayout()->getStringRepresentation());

    llvm::DataLayout *dataLayout = new llvm::DataLayout(module);
    passManager.add(dataLayout);

    passManager.run(*module);
    return true;
}
