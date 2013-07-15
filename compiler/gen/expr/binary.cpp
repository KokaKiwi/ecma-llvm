#include <map>
#include <utility>
#include <stdexcept>
#include <llvm/IR/Value.h>
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/expr/binary.h"
#include "ecma/gen/helper/call.h"

using namespace ecma;
using namespace ecma::gen;

#define OPERATOR(TYPE, FNAME) std::make_pair(ast::expr::Binary::Type::TYPE, FNAME),
static const std::map<ast::expr::Binary::Type, const char *> operators {
    OPERATOR(LogicalOr, "Ecma_Operator_LogicalOr")
    OPERATOR(LogicalAnd, "Ecma_Operator_LogicalAnd")
    OPERATOR(BitwiseOr, "Ecma_Operator_BitwiseOr")
    OPERATOR(BitwiseXor, "Ecma_Operator_BitwiseXor")
    OPERATOR(BitwiseAnd, "Ecma_Operator_BitwiseAnd")
    OPERATOR(Equal, "Ecma_Operator_Equal")
    OPERATOR(NotEqual, "Ecma_Operator_NotEqual")
    OPERATOR(Identity, "Ecma_Operator_Identity")
    OPERATOR(NotIdentity, "Ecma_Operator_NotIdentity")
    OPERATOR(Lesser, "Ecma_Operator_Lesser")
    OPERATOR(LesserOrEqual, "Ecma_Operator_LesserOrEqual")
    OPERATOR(Greater, "Ecma_Operator_Greater")
    OPERATOR(GreaterOrEqual, "Ecma_Operator_GreaterOrEqual")
    OPERATOR(InstanceOf, "Ecma_Operator_InstanceOf")
    OPERATOR(In, "Ecma_Operator_In")
    OPERATOR(LeftShift, "Ecma_Operator_LeftShift")
    OPERATOR(RightShift, "Ecma_Operator_RightShift")
    OPERATOR(Plus, "Ecma_Operator_Plus")
    OPERATOR(Minus, "Ecma_Operator_Minus")
    OPERATOR(Mul, "Ecma_Operator_Mul")
    OPERATOR(Div, "Ecma_Operator_Div")
    OPERATOR(Mod, "Ecma_Operator_Mod")
};

void GPEVisitor::visit(ast::expr::Binary &binary)
{
    ast::Expression *left = binary.left();
    ast::Expression *right = binary.right();

    if (left == nullptr && right == nullptr)
    {
        throw std::runtime_error("Both operands missing.");
    }

    if (left == nullptr)
    {
        throw std::runtime_error("Left operand missing");
    }

    if (right == nullptr)
    {
        throw std::runtime_error("Right operand missing");
    }

    llvm::Value *leftValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*left);
    llvm::Value *rightValue = GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*right);

    m_value = gen::helper::call(m_context, m_module, m_irBuilder, operators.at(binary.type()), leftValue, rightValue);
}
