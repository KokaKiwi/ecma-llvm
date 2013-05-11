#include <stdexcept>
#include <llvm/Value.h>
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/Function.h>
#include "ecma/gen/code.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/stmt/ctrl/while.h"
#include "ecma/ast/expression.h"
#include "ecma/ast/statement.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::ctrl::While &stmt)
{
    ast::Expression *expr = stmt.expr();
    ast::Statement *thenBranch = stmt.thenBranch();

    if (expr == nullptr)
    {
        throw std::runtime_error("Missing condition.");
    }

    if (thenBranch == nullptr)
    {
        throw std::runtime_error("Missing then branch.");
    }

    llvm::Function *function = m_irBuilder.GetInsertBlock()->getParent();

    llvm::BasicBlock *testBlock = llvm::BasicBlock::Create(m_context, "test");
    llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(m_context, "then");
    llvm::BasicBlock *finallyBlock = llvm::BasicBlock::Create(m_context, "finally");

    if (!stmt.doFirst())
    {
        m_irBuilder.CreateBr(testBlock);
        function->getBasicBlockList().push_back(testBlock);
        m_irBuilder.SetInsertPoint(testBlock);

        llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
        llvm::Value *exprBoolValue = Ecma_boolCast(m_context, m_module, m_irBuilder, exprValue);
        llvm::Value *test = m_irBuilder.CreateICmpEQ(exprBoolValue, llvm::ConstantInt::getTrue(m_context));

        m_irBuilder.CreateCondBr(test, thenBlock, finallyBlock);
    }
    else
    {
        m_irBuilder.CreateBr(thenBlock);
    }

    function->getBasicBlockList().push_back(thenBlock);
    m_irBuilder.SetInsertPoint(thenBlock);

    thenBranch->accept(*this);

    m_irBuilder.CreateBr(testBlock);

    if (stmt.doFirst())
    {
        function->getBasicBlockList().push_back(testBlock);
        m_irBuilder.SetInsertPoint(testBlock);

        llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
        llvm::Value *exprBoolValue = Ecma_boolCast(m_context, m_module, m_irBuilder, exprValue);
        llvm::Value *test = m_irBuilder.CreateICmpEQ(exprBoolValue, llvm::ConstantInt::getTrue(m_context));

        m_irBuilder.CreateCondBr(test, thenBlock, finallyBlock);
    }

    function->getBasicBlockList().push_back(finallyBlock);
    m_irBuilder.SetInsertPoint(finallyBlock);
}
