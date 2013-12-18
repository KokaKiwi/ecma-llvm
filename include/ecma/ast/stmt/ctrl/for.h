#ifndef ECMA_AST_STMT_CTRL_FOR_H_
#define ECMA_AST_STMT_CTRL_FOR_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class For: public Statement
                {
                    public:
                        inline For(Statement *init, Statement *cond, Statement *loop, Statement *action)
                            : Statement()
                            , m_init(init)
                            , m_cond(cond)
                            , m_loop(loop)
                            , m_action(action)
                        {
                        }
                        virtual inline ~For()
                        {
                        }

                        inline const Statement *init() const
                        {
                            return m_init.get();
                        }
                        inline For &init(Statement *init)
                        {
                            m_init.reset(init);
                            return *this;
                        }
                        inline Statement *take_init()
                        {
                            return m_init.release();
                        }

                        inline const Statement *cond() const
                        {
                            return m_cond.get();
                        }
                        inline For &cond(Statement *cond)
                        {
                            m_cond.reset(cond);
                            return *this;
                        }
                        inline Statement *take_cond()
                        {
                            return m_cond.release();
                        }

                        inline const Statement *loop() const
                        {
                            return m_loop.get();
                        }
                        inline For &loop(Statement *loop)
                        {
                            m_loop.reset(loop);
                            return *this;
                        }
                        inline Statement *take_loop()
                        {
                            return m_loop.release();
                        }

                        inline const Statement *action() const
                        {
                            return m_action.get();
                        }
                        inline For &action(Statement *action)
                        {
                            m_action.reset(action);
                            return *this;
                        }
                        inline Statement *take_action()
                        {
                            return m_action.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Statement> m_init;
                        std::unique_ptr<Statement> m_cond;
                        std::unique_ptr<Statement> m_loop;
                        std::unique_ptr<Statement> m_action;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_FOR_H_ */