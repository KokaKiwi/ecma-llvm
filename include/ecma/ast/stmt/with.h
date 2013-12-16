#ifndef ECMA_AST_STMT_WITH_H_
#define ECMA_AST_STMT_WITH_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class With: public Statement
            {
                public:
                    inline With(Expression *expr, Statement *action)
                        : Statement()
                        , m_expr(expr)
                        , m_action(action)
                    {
                    }
                    inline ~With()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline With &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *expr()
                    {
                        return m_expr.release();
                    }

                    inline const Statement *action() const
                    {
                        return m_action.get();
                    }
                    inline With &action(Statement *action)
                    {
                        m_action.reset(action);
                        return *this;
                    }
                    inline Statement *action()
                    {
                        return m_action.release();
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
                    std::unique_ptr<Statement> m_action;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_WITH_H_ */
