#include <vector>
#include <llvm/Constants.h>
#include <llvm/DerivedTypes.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/call.h"
#include "ecma/runtime/capi.call.h"
#include "ecma/gen/helper/type.h"
#include "ecma/gen/helper/string.h"

using namespace ecma;
using namespace ecma::gen;

void GPEVisitor::visit(ast::expr::Call &call)
{
    llvm::Value *callee = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*call.expr());
    int argc = call.args() ? call.args()->size() : 0;
    llvm::Value *argcValue = llvm::ConstantInt::get(gen::helper::type<int>(m_context), argc);

    llvm::ArrayType *type = llvm::ArrayType::get(gen::helper::type<runtime::Object *>(m_context), argc);
    llvm::Value *args = m_irBuilder.CreateAlloca(type);

    if (call.args())
    {
        for (int i = 0; i < argc; i++)
        {
            llvm::Value *argValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*(*call.args())[i]);
            llvm::Value *argPtr = m_irBuilder.CreateStructGEP(args, i);
            m_irBuilder.CreateStore(argValue, argPtr);
        }
    }

    llvm::Value *argv = m_irBuilder.CreateStructGEP(args, 0);

    m_value = Ecma_call(m_context, m_module, m_irBuilder, callee, argcValue, argv);
}
