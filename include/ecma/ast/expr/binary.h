#ifndef ECMA_AST_EXPR_BINARY_H_
#define ECMA_AST_EXPR_BINARY_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Binary: public Expression
            {
                public:
                    enum class OpType
                    {
                        PLUS,
                        MINUS,
                        MUL,
                        DIV,
                        MOD,
                        LEFT_SHIFT,
                        RIGHT_SHIFT,
                        ZERO_RIGHT_SHIFT,
                        LESSER_THAN,
                        GREATER_THAN,
                        LESSER_EQ_THAN,
                        GREATER_EQ_THAN,
                        INSTANCEOF,
                        IN,
                        EQUAL,
                        NOT_EQUAL,
                        STRICT_EQUAL,
                        STRICT_NOT_EQUAL,
                        BIT_AND,
                        BIT_XOR,
                        BIT_OR,
                        LOGIC_AND,
                        LOGIC_OR,
                    };

                    inline Binary(Expression *left, Expression *right, OpType op)
                        : Expression()
                        , m_left(left)
                        , m_right(right)
                        , m_op(op)
                    {
                    }
                    virtual inline ~Binary()
                    {
                    }

                    inline const Expression *left() const
                    {
                        return m_left.get();
                    }
                    inline Binary &left(Expression *left)
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
                    inline Binary &right(Expression *right)
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
                    inline Binary &op(OpType op)
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

#endif /* ECMA_AST_EXPR_BINARY_H_ */
