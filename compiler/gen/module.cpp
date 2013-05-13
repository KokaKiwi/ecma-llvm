#include <llvm/Module.h>
#include <llvm/LLVMContext.h>
#include <llvm/Function.h>
#include <llvm/BasicBlock.h>
#include <llvm/IRBuilder.h>
#include <llvm/Constants.h>
#include "ecma/gen/module.h"
#include "ecma/gen/code.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/scope.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

llvm::Module *ModuleBuilder::build(llvm::LLVMContext &context, llvm::Module *module) const
{
    llvm::Function *mainFunction = llvm::Function::Create(gen::helper::type<int (int, char *)>(context), llvm::GlobalVariable::ExternalLinkage, "main", module);

    llvm::BasicBlock *bootstrapBlock = llvm::BasicBlock::Create(context, "bootstrap");
    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");

    mainFunction->getBasicBlockList().push_back(bootstrapBlock);
    mainFunction->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(context);
    irBuilder.SetInsertPoint(bootstrapBlock);
    irBuilder.CreateBr(entryBlock);
    irBuilder.SetInsertPoint(entryBlock);

    llvm::Value *env = Ecma_Object_create(context, module, irBuilder);
    env->setName("env");
    Scope scope(context, module, env);

    gen::CodeBuilder(m_program)
        .build(context, module, irBuilder, scope);

    llvm::BasicBlock &lastBlock = mainFunction->getBasicBlockList().back();
    if (lastBlock.empty() || !lastBlock.back().isTerminator())
    {
        irBuilder.SetInsertPoint(&lastBlock, lastBlock.end());
        irBuilder.CreateRet(llvm::ConstantInt::get(gen::helper::type<int>(context), 0));
    }

    return module;
}
