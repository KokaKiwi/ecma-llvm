#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/gen/svisitor.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Block &block)
{
    for (ast::Statement *stmt : block.statements())
    {
        stmt->accept(*this);
    }
}
