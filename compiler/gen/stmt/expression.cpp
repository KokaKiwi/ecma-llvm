#include "ecma/ast/stmt/expression.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/evisitor.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Expression &expr)
{
    EVisitor visitor(m_context, m_module, m_irBuilder, m_scope);

    expr.expr()->accept(visitor);
}
