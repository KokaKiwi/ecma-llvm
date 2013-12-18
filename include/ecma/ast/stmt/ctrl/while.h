#ifndef ECMA_AST_STMT_CTRL_WHILE_H_
#define ECMA_AST_STMT_CTRL_WHILE_H_

#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class While: public Statement
                {
                    public:
                        inline While(bool action_first, Expression *cond_expr, Statement *action)
                            : Statement()
                            , m_action_first(action_first)
                            , m_cond_expr(cond_expr)
                            , m_action(action)
                        {
                        }
                        virtual inline ~While()
                        {
                        }

                        inline const Expression *cond_expr() const
                        {
                            return m_cond_expr.get();
                        }
                        inline While &cond_expr(Expression *cond_expr)
                        {
                            m_cond_expr.reset(cond_expr);
                            return *this;
                        }
                        inline Expression *take_cond_expr()
                        {
                            return m_cond_expr.release();
                        }

                        inline const Statement *action() const
                        {
                            return m_action.get();
                        }
                        inline While &action(Statement *action)
                        {
                            m_action.reset(action);
                            return *this;
                        }
                        inline Statement *take_action()
                        {
                            return m_action.release();
                        }

                        inline const bool action_first() const
                        {
                            return m_action_first;
                        }
                        inline While &action_first(bool action_first)
                        {
                            m_action_first = action_first;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Expression> m_cond_expr;
                        std::unique_ptr<Statement> m_action;
                        bool m_action_first;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_WHILE_H_ */
