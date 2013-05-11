#include <llvm/Constants.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/literal/boolean.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::Boolean &boolean)
{
    m_value = Ecma_Boolean_create(m_context, m_module, m_irBuilder, llvm::ConstantInt::get(gen::helper::type<bool>(m_context), boolean.value()));
}
