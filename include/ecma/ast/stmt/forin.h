#ifndef ECMA_AST_STMT_FORIN_H_
#define ECMA_AST_STMT_FORIN_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class ForIn: public Statement
            {
                public:
                    inline ForIn(Expression *counter, Expression *expr, Statement *action)
                        : Statement()
                        , m_counter(counter)
                        , m_expr(expr)
                        , m_action(action)
                    {
                    }
                    inline ~ForIn()
                    {
                    }

                    inline const Expression *counter() const
                    {
                        return m_counter.get();
                    }
                    inline ForIn &counter(Expression *counter)
                    {
                        m_counter.reset(counter);
                        return *this;
                    }
                    inline Expression *counter()
                    {
                        return m_counter.release();
                    }

                    inline const Expression *init() const
                    {
                        return m_init.get();
                    }
                    inline ForIn &init(Expression *init)
                    {
                        m_init.reset(init);
                        return *this;
                    }
                    inline Expression *init()
                    {
                        return m_init.release();
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline ForIn &expr(Expression *expr)
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
                    inline ForIn &action(Statement *action)
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
                    std::unique_ptr<Expression> m_counter;
                    std::unique_ptr<Expression> m_init;
                    std::unique_ptr<Expression> m_expr;
                    std::unique_ptr<Statement> m_action;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_FORIN_H_ */
