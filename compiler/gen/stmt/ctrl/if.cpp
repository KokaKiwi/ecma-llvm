#include <stdexcept>
#include <llvm/Value.h>
#include <llvm/BasicBlock.h>
#include <llvm/Constants.h>
#include <llvm/Function.h>
#include "ecma/gen/code.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/stmt/ctrl/if.h"
#include "ecma/ast/expression.h"
#include "ecma/ast/statement.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::ctrl::If &stmt)
{
    ast::Expression *expr = stmt.expr();
    ast::Statement *thenBranch = stmt.thenBranch();
    ast::Statement *elseBranch = stmt.elseBranch();

    if (expr == nullptr)
    {
        throw std::runtime_error("Missing condition.");
    }

    if (thenBranch == nullptr)
    {
        throw std::runtime_error("Missing then statement.");
    }

    llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
    llvm::Value *exprBoolValue = Ecma_boolCast(m_context, m_module, m_irBuilder, exprValue);
    llvm::Value *test = m_irBuilder.CreateICmpEQ(exprBoolValue, llvm::ConstantInt::getTrue(m_context));

    llvm::Function *function = m_irBuilder.GetInsertBlock()->getParent();

    if (elseBranch != nullptr)
    {
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(m_context, "then");
        llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(m_context, "else");
        llvm::BasicBlock *finallyBlock = llvm::BasicBlock::Create(m_context, "finally");

        m_irBuilder.CreateCondBr(test, thenBlock, elseBlock);

        function->getBasicBlockList().push_back(thenBlock);
        m_irBuilder.SetInsertPoint(thenBlock);
        thenBranch->accept(*this);
        if (thenBlock->empty() || !thenBlock->back().isTerminator())
        {
            m_irBuilder.CreateBr(finallyBlock);
        }

        function->getBasicBlockList().push_back(elseBlock);
        m_irBuilder.SetInsertPoint(elseBlock);
        elseBranch->accept(*this);
        if (elseBlock->empty() || !elseBlock->back().isTerminator())
        {
            m_irBuilder.CreateBr(finallyBlock);
        }

        if (thenBlock->empty() || !thenBlock->back().isTerminator()
            || elseBlock->empty() || !elseBlock->back().isTerminator())
        {
            function->getBasicBlockList().push_back(finallyBlock);
            m_irBuilder.SetInsertPoint(finallyBlock);
        }
    }
    else
    {
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(m_context, "then");
        llvm::BasicBlock *finallyBlock = llvm::BasicBlock::Create(m_context, "finally");

        m_irBuilder.CreateCondBr(test, thenBlock, finallyBlock);

        function->getBasicBlockList().push_back(thenBlock);
        m_irBuilder.SetInsertPoint(thenBlock);
        thenBranch->accept(*this);
        if (thenBlock->empty() || !thenBlock->back().isTerminator())
        {
            m_irBuilder.CreateBr(finallyBlock);
        }

        function->getBasicBlockList().push_back(finallyBlock);
        m_irBuilder.SetInsertPoint(finallyBlock);
    }
}
