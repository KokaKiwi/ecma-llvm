#include <llvm/Value.h>
#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/binary.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::Binary &binary)
{
    llvm::Value *left = binary.left() ? run(*binary.left()) : nullptr;
    llvm::Value *right = binary.right() ? run(*binary.right()) : nullptr;

    m_value = nullptr;
    switch(binary.op())
    {
        case ast::expr::Binary::Operator::Addition:
            m_value = m_irBuilder.CreateAdd(left, right);
            break;

        case ast::expr::Binary::Operator::Substraction:
            m_value = m_irBuilder.CreateSub(left, right);
            break;

        case ast::expr::Binary::Operator::Multiplication:
            m_value = m_irBuilder.CreateMul(left, right);
            break;

        case ast::expr::Binary::Operator::Division:
            m_value = m_irBuilder.CreateSDiv(left, right);
            break;

        case ast::expr::Binary::Operator::Modulo:
            break;
    }
}
