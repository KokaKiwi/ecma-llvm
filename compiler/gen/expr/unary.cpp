#include <map>
#include <utility>
#include <stdexcept>
#include <llvm/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/unary.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Unary &unary)
{
    ast::Expression *expr = unary.expr();

    if (expr == nullptr)
    {
        throw std::runtime_error("Missing expression");
    }

    llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
    m_value = exprValue;

    switch (unary.type())
    {
        case ast::expr::Unary::Type::Not:
            m_value = Ecma_Operator_Not(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::Inv:
            m_value = Ecma_Operator_Inv(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::Plus:
            m_value = Ecma_Operator_Positive(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::Minus:
            m_value = Ecma_Operator_Negative(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::PreIncrementation:
            m_value = Ecma_Operator_Incrementation(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::PreDecrementation:
            m_value = Ecma_Operator_Decrementation(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::TypeOf:
            m_value = Ecma_Operator_TypeOf(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::PostIncrementation:
            Ecma_Operator_Incrementation(m_context, m_module, m_irBuilder, exprValue);
            break;
        case ast::expr::Unary::Type::PostDecrementation:
            Ecma_Operator_Decrementation(m_context, m_module, m_irBuilder, exprValue);
            break;
    }
}
