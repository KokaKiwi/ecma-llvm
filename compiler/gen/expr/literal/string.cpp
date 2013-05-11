#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/literal/string.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::String &str)
{
    m_value = Ecma_String_create(m_context, m_module, m_irBuilder, gen::helper::string(m_irBuilder, str.value()));
}
