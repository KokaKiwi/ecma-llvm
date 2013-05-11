#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/identifier.h"

using namespace ecma;
using namespace ecma::gen;

void LSEVisitor::visit(ast::expr::Identifier &id)
{
    m_scope.set(m_irBuilder, id.name(), m_value);
}

void GPEVisitor::visit(ast::expr::Identifier &id)
{
    m_value = m_scope.get(m_irBuilder, id.name());
}
