#include <llvm/Constants.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/literal/undefined.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::Undefined &undef)
{
    m_value = Ecma_Undefined_create(m_context, m_module, m_irBuilder);
}
