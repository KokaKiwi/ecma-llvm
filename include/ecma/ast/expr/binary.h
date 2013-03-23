#ifndef ECMA_AST_EXPR_BINARY_H_
#define ECMA_AST_EXPR_BINARY_H_

#include <memory>
#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Binary: public ast::Expression
            {
            public:
                enum class Operator;

                Binary(Operator op, ast::Expression *left = nullptr, ast::Expression *right = nullptr): m_op(op), m_left(left), m_right(right) {}

                inline Operator op(void) const
                {
                    return m_op;
                }
                inline Binary &op(Operator op)
                {
                    m_op = op;
                    return *this;
                }

                inline ast::Expression *left(void) const
                {
                    return m_left.get();
                }
                inline Binary &left(ast::Expression *left)
                {
                    m_left.reset(left);
                    return *this;
                }
                inline ast::Expression *takeLeft(void)
                {
                    return m_left.release();
                }

                inline ast::Expression *right(void) const
                {
                    return m_right.get();
                }
                inline Binary &right(ast::Expression *right)
                {
                    m_right.reset(right);
                    return *this;
                }
                inline ast::Expression *takeRight(void)
                {
                    return m_right.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                Operator m_op;
                std::unique_ptr<ast::Expression> m_left;
                std::unique_ptr<ast::Expression> m_right;
            };

            enum class Binary::Operator
            {
                Addition,
                Substraction,
                Multiplication,
                Division,
                Modulo
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_BINARY_H_ */
