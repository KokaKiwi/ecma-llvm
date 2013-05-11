#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/member.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void LSEVisitor::visit(ast::expr::Member &member)
{
    llvm::Value *instance = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*member.expr());
    Ecma_setProperty(m_context, m_module, m_irBuilder, instance, gen::helper::string(m_irBuilder, member.name()), m_value);
}

void GPEVisitor::visit(ast::expr::Member &member)
{
    llvm::Value *instance = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*member.expr());
    m_value = Ecma_getProperty(m_context, m_module, m_irBuilder, instance, gen::helper::string(m_irBuilder, member.name()));
}
