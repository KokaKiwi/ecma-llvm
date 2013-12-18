#ifndef ECMA_AST_EXPR_NEW_H_
#define ECMA_AST_EXPR_NEW_H_

#include <vector>
#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class New: public Expression
            {
                public:
                    inline New()
                        : Expression()
                    {
                    }
                    virtual inline ~New()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline New &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *take_expr()
                    {
                        return m_expr.release();
                    }

                    inline const std::vector<std::unique_ptr<Expression>> &args() const
                    {
                        return m_args;
                    }
                    inline std::vector<std::unique_ptr<Expression>> &args()
                    {
                        return m_args;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
                    std::vector<std::unique_ptr<Expression>> m_args;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_NEW_H_ */
