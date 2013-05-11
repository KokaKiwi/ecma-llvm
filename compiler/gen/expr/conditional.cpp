#include <stdexcept>
#include <llvm/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/conditional.h"
#include "ecma/ast/expression.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Conditional &cond)
{
    ast::Expression *expr = cond.expr();
    ast::Expression *thenExpr = cond.thenExpr();
    ast::Expression *elseExpr = cond.elseExpr();

    if (expr == nullptr)
    {
        throw std::runtime_error("Missing condition.");
    }
    if (thenExpr == nullptr)
    {
        throw std::runtime_error("Missing then expression.");
    }
    if (elseExpr == nullptr)
    {
        throw std::runtime_error("Missing else expression.");
    }

    llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
    llvm::Value *exprBoolValue = Ecma_boolCast(m_context, m_module, m_irBuilder, exprValue);
    llvm::Value *test = m_irBuilder.CreateICmpEQ(exprBoolValue, llvm::ConstantInt::getTrue(m_context));

    llvm::Value *thenValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*thenExpr);
    llvm::Value *elseValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*elseExpr);

    m_value = m_irBuilder.CreateSelect(test, thenValue, elseValue);
}
