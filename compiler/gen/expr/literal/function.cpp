#include <string>
#include <sstream>
#include <llvm/Constants.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/function.h"
#include "ecma/ast/expr/literal/integer.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::literal::Function &function)
{
    m_value = FunctionBuilder("", &function).build(m_context, m_module, m_irBuilder, m_scope);
}
