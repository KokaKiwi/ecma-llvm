#include <stdexcept>
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expression.h"
#include "ecma/ast/stmt/return.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Return &ret)
{
    ast::Expression *expr = ret.expr();

    llvm::Value *value;
    if (expr == nullptr)
    {
        value = Ecma_Undefined_create(m_context, m_module, m_irBuilder);
    }
    else
    {
        value = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
    }
    m_irBuilder.CreateRet(value);
}
