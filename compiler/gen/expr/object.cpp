#include <llvm/IR/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/object.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Object &object)
{
    m_value = Ecma_Object_create(m_context, m_module, m_irBuilder);
    if (object.properties())
    {
        for (ast::expr::Object::Property *property : *object.properties())
        {
            std::string name = *property->key();
            llvm::Value *value = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*property->value());
            Ecma_setProperty(m_context, m_module, m_irBuilder, m_value, gen::helper::string(m_irBuilder, name), value);
        }
    }
}
