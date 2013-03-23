#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/assignment.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::Assignment &assign)
{
    EVisitor visitor(m_context, m_module, m_irBuilder, m_scope);

    llvm::Value *value = visitor.run(*assign.value());
    llvm::Value *var = scope().set(assign.name(), value);
    m_value = value;
}
