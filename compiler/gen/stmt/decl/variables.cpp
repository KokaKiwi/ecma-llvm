#include <llvm/IR/Value.h>
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/stmt/decl/variables.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::decl::Variables &vars)
{
    for (ast::stmt::decl::Variables::Variable *var : vars.vars())
    {
        if (var->initializer() != nullptr)
        {
            llvm::Value *initializer = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*var->initializer());
            initializer->setName(var->name());

            m_scope.declare(m_irBuilder, var->name(), initializer);
        }
        else
        {
            m_scope.declare(m_irBuilder, var->name());
        }
    }
}
