#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/array.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/runtime/object.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Array &array)
{
    int size = array.values() ? array.values()->size() : 0;
    llvm::Value *sizeValue = llvm::ConstantInt::get(gen::helper::type<int>(m_context), size);

    llvm::ArrayType *type = llvm::ArrayType::get(gen::helper::type<runtime::Object *>(m_context), size);
    llvm::Value *values = m_irBuilder.CreateAlloca(type);

    for (int i = 0; i < size; i++)
    {
        ast::Expression *value = (*array.values())[i];
        llvm::Value *valueValue;
        if (value)
        {
            valueValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*(*array.values())[i]);
        }
        else
        {
            valueValue = Ecma_Undefined_create(m_context, m_module, m_irBuilder);
        }
        llvm::Value *ptr = m_irBuilder.CreateStructGEP(values, i);
        m_irBuilder.CreateStore(valueValue, ptr);
    }

    llvm::Value *elems = m_irBuilder.CreateStructGEP(values, 0);

    m_value = Ecma_Array_create(m_context, m_module, m_irBuilder, sizeValue, elems);
}
