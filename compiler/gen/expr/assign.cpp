#include <map>
#include <utility>
#include <stdexcept>
#include <llvm/IR/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/gen/lsevisitor.h"
#include "ecma/ast/expr/assign.h"
#include "ecma/ast/expression.h"
#include "ecma/gen/helper/call.h"

using namespace ecma;
using namespace ecma::gen;

#define OPERATOR(TYPE, FNAME) std::make_pair(ast::expr::Assign::Type::TYPE, FNAME),
static const std::map<ast::expr::Assign::Type, const char *> operators {
    OPERATOR(PlusAssign, "Ecma_Operator_Plus")
    OPERATOR(MinusAssign, "Ecma_Operator_Minus")
    OPERATOR(MulAssign, "Ecma_Operator_Mul")
    OPERATOR(DivAssign, "Ecma_Operator_Div")
    OPERATOR(ModAssign, "Ecma_Operator_Mod")
    OPERATOR(RightShiftAssign, "Ecma_Operator_RightShift")
    OPERATOR(BinaryAndAssign, "Ecma_Operator_BitwiseAnd")
    OPERATOR(BinaryOrAssign, "Ecma_Operator_BitwiseOr")
    OPERATOR(XorAssign, "Ecma_Operator_BitwiseXor")
};

void GPEVisitor::visit(ast::expr::Assign &assign)
{
    ast::Expression *left = assign.left();
    ast::Expression *expr = assign.expr();

    llvm::Value *exprValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);

    if (assign.type() == ast::expr::Assign::Type::Assign)
    {
        m_value = exprValue;
    }
    else
    {
        llvm::Value *leftValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*left);
        m_value = gen::helper::call(m_context, m_module, m_irBuilder, operators.at(assign.type()), leftValue, exprValue);
    }

    LSEVisitor(m_context, m_module, m_irBuilder, m_scope, m_value).run(*left);
}
