#ifndef ECMA_AST_EXPR_CONDITION_H_
#define ECMA_AST_EXPR_CONDITION_H_

#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Condition: public Expression
            {
                public:
                    inline Condition(Expression *cond_expr, Expression *then_expr, Expression *else_expr)
                        : Expression()
                        , m_cond_expr(cond_expr)
                        , m_then_expr(then_expr)
                        , m_else_expr(else_expr)
                    {
                    }
                    virtual inline ~Condition()
                    {
                    }

                    inline const Expression *cond_expr() const
                    {
                        return m_cond_expr.get();
                    }
                    inline Condition &cond_expr(Expression *cond_expr)
                    {
                        m_cond_expr.reset(cond_expr);
                        return *this;
                    }
                    inline Expression *take_cond_expr()
                    {
                        return m_cond_expr.release();
                    }

                    inline const Expression *then_expr() const
                    {
                        return m_then_expr.get();
                    }
                    inline Condition &then_expr(Expression *then_expr)
                    {
                        m_then_expr.reset(then_expr);
                        return *this;
                    }
                    inline Expression *take_then_expr()
                    {
                        return m_then_expr.release();
                    }

                    inline const Expression *else_expr() const
                    {
                        return m_else_expr.get();
                    }
                    inline Condition &else_expr(Expression *else_expr)
                    {
                        m_else_expr.reset(else_expr);
                        return *this;
                    }
                    inline Expression *take_else_expr()
                    {
                        return m_else_expr.release();
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_cond_expr;
                    std::unique_ptr<Expression> m_then_expr;
                    std::unique_ptr<Expression> m_else_expr;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_CONDITION_H_ */
