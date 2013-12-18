#ifndef ECMA_AST_EXPR_MEMBER_H_
#define ECMA_AST_EXPR_MEMBER_H_

#include <memory>
#include <string>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Member: public Expression
            {
                public:
                    inline Member()
                        : Expression()
                    {
                    }
                    virtual inline ~Member()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Member &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *take_expr()
                    {
                        return m_expr.release();
                    }

                    inline const std::string name() const
                    {
                        return m_name;
                    }
                    inline Member &name(std::string name)
                    {
                        m_name = name;
                        return *this;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
                    std::string m_name;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_MEMBER_H_ */
