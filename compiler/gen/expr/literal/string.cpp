#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/literal/string.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::literal::String &string)
{
    m_value = m_irBuilder.CreateGlobalStringPtr(string.escape().value());
}
