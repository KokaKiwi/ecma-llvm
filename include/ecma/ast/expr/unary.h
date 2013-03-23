#ifndef ECMA_AST_EXPR_UNARY_H_
#define ECMA_AST_EXPR_UNARY_H_

#include <memory>
#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Unary: public ast::Expression
            {
            public:
                enum class Operator;

                inline Unary(Operator op, ast::Expression *expr): m_op(op), m_expr(expr) {}

                inline Operator op(void) const
                {
                    return m_op;
                }
                inline Unary &op(Operator op)
                {
                    m_op = op;
                    return *this;
                }

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline Unary &expr(ast::Expression *expr)
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
                Operator m_op;
                std::unique_ptr<ast::Expression> m_expr;
            };

            enum class Unary::Operator
            {
                Not,
                Inv,

                Positive,
                Negative
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_UNARY_H_ */
