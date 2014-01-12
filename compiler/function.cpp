#include <vector>
#include <memory>
#include <llvm/ADT/ilist.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include "ecma/ast/statement.h"
#include "ecma/compiler/function.h"
#include "llvmpp/helper/type.h"
#include "ecma/runtime/scope.h"

using namespace ecma;
using namespace ecma::compiler;

static llvm::FunctionType *GetFunctionSignature(llvm::LLVMContext &context)
{
    llvm::Type *retType = llvmpp::helper::type<void>(context);
    std::vector<llvm::Type *> argTypes;

    llvm::Type *envType = runtime::Scope::GetEnvType(context);
    argTypes.push_back(llvm::PointerType::get(envType, 0));

    return llvm::FunctionType::get(retType, argTypes, false);
}

void Function::compile(llvm::LLVMContext &context, const std::vector<std::unique_ptr<ast::Statement>> &statements)
{
    llvm::Function *function = llvm::Function::Create(GetFunctionSignature(context), llvm::GlobalVariable::ExternalLinkage, name(), module());

    auto args = function->getArgumentList().begin();

    llvm::Value *envValue = args++;
    envValue->setName("env");

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry");
    function->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(context);
    irBuilder.SetInsertPoint(entryBlock);

    llvm::BasicBlock &lastBlock = function->getBasicBlockList().back();
    if (lastBlock.empty() || !lastBlock.back().isTerminator())
    {
        irBuilder.SetInsertPoint(&lastBlock, lastBlock.end());
        irBuilder.CreateRetVoid();
    }
}
