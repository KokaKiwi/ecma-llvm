#ifndef ECMA_AST_EXPR_UNARY_H_
#define ECMA_AST_EXPR_UNARY_H_

#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Unary: public Expression
            {
                public:
                    enum class OpType
                    {
                        DELETE,
                        VOID,
                        TYPEOF,
                        INCREMENT,
                        DECREMENT,
                        PLUS,
                        MINUS,
                        INV,
                        NOT,
                    };

                    inline Unary(Expression *expr, OpType op)
                        : Expression()
                        , m_expr(expr)
                        , m_op(op)
                    {
                    }
                    virtual inline ~Unary()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Unary &expr(Expression *expr)
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
                    inline Unary &op(OpType op)
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

#endif /* ECMA_AST_EXPR_UNARY_H_ */
