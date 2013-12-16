#ifndef ECMA_AST_STMT_SWITCH_H_
#define ECMA_AST_STMT_SWITCH_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Switch: public Statement
            {
                public:
                    inline Switch(Expression *expr)
                        : Statement()
                        , m_expr(expr)
                    {}

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Switch &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *expr()
                    {
                        return m_expr.release();
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_SWITCH_H_ */
