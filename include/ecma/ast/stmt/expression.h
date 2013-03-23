#ifndef ECMA_AST_STMT_EXPRESSION_H_
#define ECMA_AST_STMT_EXPRESSION_H_

#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Expression: public ast::Statement
            {
            public:
                Expression(ast::Expression *expr = nullptr): m_expr(expr) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline Expression &expr(ast::Expression *expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_EXPRESSION_H_ */
