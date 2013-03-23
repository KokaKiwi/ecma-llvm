#include <iostream>
#include "ecma/ast/stmt/decl/variables.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/evisitor.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::decl::Variables &vars)
{
    for (ast::stmt::decl::Variables::Variable *var : vars.variables())
    {
        if (var->initializer())
        {
            EVisitor visitor(m_context, m_module, m_irBuilder, m_scope);
            llvm::Value *value = visitor.run(*var->initializer());

            scope().set(var->name(), value);
        }
        else
        {
            scope().declare(var->name(), gen::helper::type<int>(m_context));
        }
    }
}
