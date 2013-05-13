#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/this.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void LSEVisitor::visit(ast::expr::This &thisExpr)
{
    m_scope.thisValue(m_value);
}

void GPEVisitor::visit(ast::expr::This &thisExpr)
{
    if (m_scope.thisValue() == nullptr)
    {
        m_value = Ecma_Undefined_create(m_context, m_module, m_irBuilder);
    }
    else
    {
        m_value = m_scope.thisValue();
    }
}
