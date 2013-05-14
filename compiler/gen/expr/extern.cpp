#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/extern.h"
#include "ecma/gen/helper/type.h"
#include "ecma/runtime/type/function.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Extern &expr)
{
    llvm::Value *fn = m_module->getOrInsertFunction(expr.name(), gen::helper::type<runtime::type::Function::Signature>(m_context));
    m_value = Ecma_Function_create(m_context, m_module, m_irBuilder, fn);
}
