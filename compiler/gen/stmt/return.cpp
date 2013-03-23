#include <llvm/Value.h>
#include "ecma/ast/stmt/return.h"
#include "ecma/gen/svisitor.h"
#include "ecma/gen/evisitor.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Return &ret)
{
    EVisitor visitor(*this);
    llvm::Value *value = visitor.run(*ret.expr());

    m_irBuilder.CreateRet(value);
}
