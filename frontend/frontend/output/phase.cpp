#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <llvm/PassManager.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/Support/raw_os_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/Host.h>
#include <llvm/Target/TargetOptions.h>
#include "ecma/frontend/args.h"
#include "ecma/frontend/unit.h"
#include "ecma/frontend/output/phase.h"
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::frontend;
using namespace ecma::frontend::output;

void Output::init(Args &args)
{
    args.add("", false, 1, 0, "Write output to <filename>", "-o", "--output");
}

Phase::Result Output::run(Args &args, std::vector<std::unique_ptr<Unit>> &units)
{
    bool executable = !(args.isSet("-S") || args.isSet("--emit-llvm"));
    bool success = true;
    std::string output;

    if (units.size() > 1 && args.isSet("-o") && !executable)
    {
        std::cerr << "Cannot specify -o when generating multiple files." << std::endl;
        return Phase::Result::ERROR;
    }
    args.get("-o")->getString(output);

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
        if (!executable)
        {
            std::string output_path = output;

            if (!args.isSet("-o"))
            {
                output_path = (*it)->source().name();
                if (output_path != "-")
                {
                    if (args.isSet("-S") && args.isSet("--emit-llvm"))
                    {
                        output_path += EXT_LLVM;
                    }
                    else if (args.isSet("-S"))
                    {
                        output_path += EXT_ASM;
                    }
                    else if (args.isSet("--emit-llvm"))
                    {
                        output_path += EXT_LLVM_BC;
                    }
                }
            }

            auto module = (*it)->take_llvm_module();
            bool asmOutput = args.isSet("-S");
            bool llvmOutput = args.isSet("--emit-llvm");

            bool compileResult;
            if (output_path == "-")
            {
                llvm::raw_os_ostream os(std::cout);
                llvm::formatted_raw_ostream out(os);
                compileResult = outputModule(module, out, asmOutput, llvmOutput);
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
                compileResult = outputModule(module, out, asmOutput, llvmOutput);
                outputFile.keep();
            }

            (*it)->llvm_module(module);

            success = success && compileResult;
        }
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

    module->setTargetTriple(targetMachine->getTargetTriple());
    module->setDataLayout(targetMachine->getDataLayout()->getStringRepresentation());

    llvm::DataLayout *dataLayout = new llvm::DataLayout(module);
    passManager.add(dataLayout);

    if (!llvmOutput && (asmOutput))
    {
        llvm::TargetMachine::CodeGenFileType outputType = llvm::TargetMachine::CGFT_Null;

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
