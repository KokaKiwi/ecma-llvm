#include <llvm/Value.h>
#include <llvm/Type.h>
#include "ecma/gen/evisitor.h"
#include "ecma/ast/expr/literal/number.h"
#include "ecma/gen/helper/type.h"

using namespace ecma;
using namespace ecma::gen;

void EVisitor::visit(ast::expr::literal::Number &number)
{
    m_value = llvm::ConstantInt::get(gen::helper::type<int>(m_context), number.value());
}
