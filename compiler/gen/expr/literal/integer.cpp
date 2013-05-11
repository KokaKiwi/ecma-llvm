#include <llvm/Constants.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/literal/integer.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::Integer &integer)
{
    m_value = Ecma_Integer_create(m_context, m_module, m_irBuilder, llvm::ConstantInt::get(gen::helper::type<int>(m_context), integer.value()));
}
