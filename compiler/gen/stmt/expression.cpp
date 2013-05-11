#include <stdexcept>
#include "ecma/gen/svisitor.h"
#include "ecma/gen/gpevisitor.h"
#include "ecma/ast/stmt/expression.h"

using namespace ecma;
using namespace ecma::gen;

void SVisitor::visit(ast::stmt::Expression &stmt)
{
    ast::Expression *expr = stmt.expr();

    if (expr == nullptr)
    {
        throw std::runtime_error("Missing expression.");
    }

    GPEVisitor(m_context, m_module, m_irBuilder, m_scope).run(*expr);
}
