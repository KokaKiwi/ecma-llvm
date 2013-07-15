#include <llvm/IR/Constants.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/literal/null.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::Null &null)
{
    m_value = Ecma_Null_create(m_context, m_module, m_irBuilder);
}
