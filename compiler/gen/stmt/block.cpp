#include "ecma/gen/svisitor.h"
#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/runtime/capi.call.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Block &block)
{
    llvm::Value *env = Ecma_Object_create(m_context, m_module, m_irBuilder);
    env->setName("env");
    Scope scope(m_context, m_module, env, new Scope::Resolver(), &m_scope);

    SVisitor visitor(m_context, m_module, m_irBuilder, scope);

    for (ast::Statement *stmt : block.statements())
    {
        if (stmt)
        {
            stmt->accept(visitor);
        }
    }
}
