#ifndef ECMA_AST_EXPR_CONDITIONAL_H_
#define ECMA_AST_EXPR_CONDITIONAL_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Conditional: public ast::Expression
            {
            public:
                inline Conditional(ast::Expression *expr, ast::Expression *thenExpr, ast::Expression *elseExpr): m_expr(expr), m_thenExpr(thenExpr), m_elseExpr(elseExpr) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::expr::Conditional &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                inline ast::Expression *thenExpr(void) const
                {
                    return m_thenExpr.get();
                }
                inline ecma::ast::expr::Conditional &thenExpr(ast::Expression * thenExpr)
                {
                    m_thenExpr.reset(thenExpr);
                    return *this;
                }
                inline ast::Expression *takeThenexpr(void)
                {
                    return m_thenExpr.release();
                }

                inline ast::Expression *elseExpr(void) const
                {
                    return m_elseExpr.get();
                }
                inline ecma::ast::expr::Conditional &elseExpr(ast::Expression * elseExpr)
                {
                    m_elseExpr.reset(elseExpr);
                    return *this;
                }
                inline ast::Expression *takeElseexpr(void)
                {
                    return m_elseExpr.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
                std::unique_ptr<ast::Expression> m_thenExpr;
                std::unique_ptr<ast::Expression> m_elseExpr;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_CONDITIONAL_H_ */
