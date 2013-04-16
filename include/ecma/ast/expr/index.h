#ifndef ECMA_AST_EXPR_INDEX_H_
#define ECMA_AST_EXPR_INDEX_H_

#include <memory>
#include <vector>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Index: public ast::Expression
            {
            public:
                inline Index(ast::Expression *expr, ast::Expression *index): m_expr(expr), m_index(index) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::expr::Index &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                inline ast::Expression *index(void) const
                {
                    return m_index.get();
                }
                inline ecma::ast::expr::Index &index(ast::Expression * index)
                {
                    m_index.reset(index);
                    return *this;
                }
                inline ast::Expression *takeIndex(void)
                {
                    return m_index.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
                std::unique_ptr<ast::Expression> m_index;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_INDEX_H_ */
