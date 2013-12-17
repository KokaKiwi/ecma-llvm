#ifndef ECMA_AST_EXPR_CALL_H_
#define ECMA_AST_EXPR_CALL_H_

#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Call: public Expression
            {
                public:
                    inline Call(Expression *expr)
                        : Expression()
                        , m_expr(expr)
                    {
                    }
                    virtual inline ~Call()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Call &expr(Expression *expr)
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

                    virtual inline void accept(tools::Visitor &visitor)
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

#endif /* ECMA_AST_EXPR_CALL_H_ */
