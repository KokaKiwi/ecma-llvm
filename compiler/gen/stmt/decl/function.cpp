#include <llvm/Value.h>
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/function.h"
#include "ecma/gen/helper/type.h"
#include "ecma/ast/stmt/decl/function.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/runtime/type/function.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::decl::Function &function)
{
    llvm::Value *fn;

    if (function.literal() != nullptr)
    {
        fn = FunctionBuilder(function.name(), function.literal()).build(m_context, m_module, m_irBuilder, m_scope);
    }
    else
    {
        fn = m_module->getOrInsertFunction(function.name(), gen::helper::type<runtime::type::Function::Signature>(m_context));
    }

    llvm::Value *fnObject = Ecma_Function_create(m_context, m_module, m_irBuilder, fn);
    fnObject->setName(function.name());

    m_scope.set(m_irBuilder, function.name(), fnObject);
}
