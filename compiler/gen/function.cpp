#include <string>
#include <llvm/Value.h>
#include <llvm/LLVMContext.h>
#include <llvm/TypeBuilder.h>
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/IRBuilder.h>
#include <llvm/Function.h>
#include "ecma/runtime/type/function.h"
#include "ecma/gen/code.h"
#include "ecma/gen/scope.h"
#include "ecma/gen/function.h"
#include "ecma/gen/helper/type.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

llvm::Value *FunctionBuilder::build(llvm::LLVMContext &context, llvm::Module *module, llvm::IRBuilder<> &irBuilder, Scope &scope)
{
    llvm::Function *function = llvm::Function::Create(gen::helper::type<runtime::type::Function::Signature>(context), llvm::GlobalVariable::ExternalLinkage, m_name, module);
    llvm::Value *functionObject = Ecma_Function_create(context, module, irBuilder, function);

    llvm::BasicBlock *bootstrapBlock = llvm::BasicBlock::Create(context, "bootstrap");
    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");

    function->getBasicBlockList().push_back(bootstrapBlock);
    function->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> fIrBuilder(context);
    fIrBuilder.SetInsertPoint(bootstrapBlock);
    fIrBuilder.CreateBr(entryBlock);
    fIrBuilder.SetInsertPoint(entryBlock);

    llvm::Function::ArgumentListType::iterator fArgs = function->getArgumentList().begin();
    llvm::Value *argc = fArgs++;
    llvm::Value *argv = fArgs++;

    Scope fScope(context, module, &scope);

    // fScope.declare(fIrBuilder, "argc", Ecma_Integer_create(context, module, fIrBuilder, argc));

    int i = 0;
    if (m_function->args())
    {
        for (std::string &arg : *m_function->args())
        {
            fScope.declare(fIrBuilder, arg, fIrBuilder.CreateLoad(fIrBuilder.CreateConstGEP1_32(argv, i)));
            i++;
        }
    }

    CodeBuilder(m_function->block())
        .build(context, module, fIrBuilder, fScope);

    llvm::BasicBlock &lastBlock = function->getBasicBlockList().back();
    if (lastBlock.empty() || !lastBlock.back().isTerminator())
    {
        fIrBuilder.SetInsertPoint(&lastBlock, lastBlock.end());
        fIrBuilder.CreateRet(Ecma_Undefined_create(context, module, fIrBuilder));
    }

    return functionObject;
}
