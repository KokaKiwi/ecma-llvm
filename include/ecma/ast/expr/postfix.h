#ifndef ECMA_AST_EXPR_POSTFIX_H_
#define ECMA_AST_EXPR_POSTFIX_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Postfix: public Expression
            {
                public:
                    enum class OpType
                    {
                        INCREMENT,
                        DECREMENT,
                    };

                    inline Postfix(Expression *expr, OpType op)
                        : Expression()
                        , m_expr(expr)
                        , m_op(op)
                    {
                    }
                    virtual inline ~Postfix()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Postfix &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *take_expr()
                    {
                        return m_expr.release();
                    }

                    inline const OpType op() const
                    {
                        return m_op;
                    }
                    inline Postfix &op(OpType op)
                    {
                        m_op = op;
                        return *this;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
                    OpType m_op;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_POSTFIX_H_ */
