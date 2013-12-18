#ifndef ECMA_AST_EXPR_ASSIGN_H_
#define ECMA_AST_EXPR_ASSIGN_H_

#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Assign: public Expression
            {
                public:
                    enum class OpType
                    {
                        SIMPLE,
                        PLUS,
                        MINUS,
                        MUL,
                        DIV,
                        MOD,
                        LEFT_SHIFT,
                        RIGHT_SHIFT,
                        ZERO_RIGHT_SHIFT,
                        BIT_AND,
                        BIT_XOR,
                        BIT_OR,
                    };

                    inline Assign(Expression *left, Expression *right, OpType op)
                        : Expression()
                        , m_left(left)
                        , m_right(right)
                        , m_op(op)
                    {
                    }
                    virtual inline ~Assign()
                    {
                    }

                    inline const Expression *left() const
                    {
                        return m_left.get();
                    }
                    inline Assign &left(Expression *left)
                    {
                        m_left.reset(left);
                        return *this;
                    }
                    inline Expression *take_left()
                    {
                        return m_left.release();
                    }

                    inline const Expression *right() const
                    {
                        return m_right.get();
                    }
                    inline Assign &right(Expression *right)
                    {
                        m_right.reset(right);
                        return *this;
                    }
                    inline Expression *take_right()
                    {
                        return m_right.release();
                    }

                    inline const OpType op() const
                    {
                        return m_op;
                    }
                    inline Assign &op(OpType op)
                    {
                        m_op = op;
                        return *this;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_left;
                    std::unique_ptr<Expression> m_right;
                    OpType m_op;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_ASSIGN_H_ */
