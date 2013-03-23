#include <vector>
#include <llvm/Function.h>
#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/literal/function_call.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::literal::FunctionCall &call)
{
    llvm::Function *func = llvm::dyn_cast_or_null<llvm::Function>(m_module->getOrInsertFunction(call.name(), gen::helper::type<int (...)>(m_context)));

    std::vector<llvm::Value *> args;
    if (call.arguments())
    {
        for (ast::Expression *arg : *call.arguments())
        {
            llvm::Value *value = run(*arg);
            args.push_back(value);
        }
    }

    m_value = m_irBuilder.CreateCall(func, args);
}
