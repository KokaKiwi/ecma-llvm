#ifndef ECMA_AST_STMT_CTRL_TRY_H_
#define ECMA_AST_STMT_CTRL_TRY_H_

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
                class Try: public Statement
                {
                    public:
                        inline Try(stmt::Block *block)
                            : Statement()
                            , m_block(block)
                        {
                        }
                        virtual inline ~Try()
                        {
                        }

                        inline const stmt::Block *block() const
                        {
                            return m_block.get();
                        }
                        inline Try &block(stmt::Block *block)
                        {
                            m_block.reset(block);
                            return *this;
                        }
                        inline stmt::Block *take_block()
                        {
                            return m_block.release();
                        }

                        inline const stmt::ctrl::Catch *catch_action() const
                        {
                            return m_catch_action.get();
                        }
                        inline Try &catch_action(stmt::ctrl::Catch *catch_action)
                        {
                            m_catch_action.reset(catch_action);
                            return *this;
                        }
                        inline stmt::ctrl::Catch *take_catch_action()
                        {
                            return m_catch_action.release();
                        }

                        inline const stmt::ctrl::Finally *finally_action() const
                        {
                            return m_finally_action.get();
                        }
                        inline Try &finally_action(stmt::ctrl::Finally *finally_action)
                        {
                            m_finally_action.reset(finally_action);
                            return *this;
                        }
                        inline stmt::ctrl::Finally *take_finally_action()
                        {
                            return m_finally_action.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<stmt::Block> m_block;
                        std::unique_ptr<stmt::ctrl::Catch> m_catch_action;
                        std::unique_ptr<stmt::ctrl::Finally> m_finally_action;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_TRY_H_ */
