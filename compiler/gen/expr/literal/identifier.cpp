#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/literal/identifier.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::literal::Identifier &identifier)
{
    m_value = scope().get(identifier.name());
}
