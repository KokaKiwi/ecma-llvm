#include <iostream>
#include <llvm/IRBuilder.h>
#include <llvm/TypeBuilder.h>
#include <llvm/BasicBlock.h>
#include <llvm/Function.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Value.h>
#include "ecma/ast/stmt/decl/function.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/code_builder.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::decl::Function &function)
{
    llvm::Function *func = llvm::Function::Create(gen::helper::type<int (...)>(m_context), llvm::GlobalValue::ExternalLinkage, function.name(), m_module);

    llvm::BasicBlock *bootstrapBlock = llvm::BasicBlock::Create(m_context, "bootstrap");
    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(m_context, "entry");

    func->getBasicBlockList().push_back(bootstrapBlock);
    func->getBasicBlockList().push_back(entryBlock);

    llvm::IRBuilder<> irBuilder(m_context);
    irBuilder.SetInsertPoint(bootstrapBlock);
    irBuilder.CreateBr(entryBlock);
    irBuilder.SetInsertPoint(entryBlock);

    Scope scope(m_context, irBuilder);

    CodeBuilder()
        .program(function.block())
        .build(m_context, m_module, irBuilder, scope);

    llvm::BasicBlock *lastBlock = &(func->getBasicBlockList().back());
    if (lastBlock->empty() || !lastBlock->back().isTerminator())
    {
        irBuilder.SetInsertPoint(lastBlock, lastBlock->end());
        irBuilder.CreateRet(llvm::ConstantInt::get(gen::helper::type<int>(m_context), 0));
    }
}
