#include <llvm/IR/LLVMContext.h>
#include <llvm/Analysis/Verifier.h>
#include "ecma/compiler/compiler.h"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include "ecma/compiler/helper/type.h"

using namespace ecma;
using namespace ecma::compiler;

llvm::Module *Compiler::compile(llvm::LLVMContext &context, bool debug)
{
    llvm::Module *module = new llvm::Module(name(), context);

    llvm::Function *moduleFunction = llvm::Function::Create(helper::type<void ()>(context), llvm::GlobalVariable::ExternalLinkage, "ecma.module." + name(), module);

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");
    moduleFunction->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(context);
    irBuilder.SetInsertPoint(entryBlock);

    irBuilder.CreateRetVoid();

    if (debug)
    {
        llvm::verifyModule(*module);
    }

    return module;
}
