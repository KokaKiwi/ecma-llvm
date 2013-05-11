#include <llvm/Value.h>
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/function.h"
#include "ecma/ast/stmt/decl/function.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::decl::Function &function)
{
    llvm::Value *fn = FunctionBuilder(function.name(), function.literal()).build(m_context, m_module, m_irBuilder, m_scope);
    m_scope.set(m_irBuilder, function.name(), fn);
}
