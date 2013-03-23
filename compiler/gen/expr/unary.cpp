#include <llvm/Value.h>
#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/unary.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::Unary &unary)
{
    llvm::Value *value = run(*unary.expr());

    m_value = nullptr;

    switch(unary.op())
    {
        case ast::expr::Unary::Operator::Not:
            m_value = m_irBuilder.CreateNot(value);
            break;

        case ast::expr::Unary::Operator::Inv:
            break;

        case ast::expr::Unary::Operator::Positive:
            m_value = value;
            break;

        case ast::expr::Unary::Operator::Negative:
            m_value = m_irBuilder.CreateFNeg(value);
            break;
    }
}
