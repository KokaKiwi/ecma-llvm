#ifndef ECMA_AST_STMT_CTRL_FINALLY_H_
#define ECMA_AST_STMT_CTRL_FINALLY_H_

#include <memory>
#include "ecma/utils/element.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Finally: public utils::Element
                {
                    public:
                        inline Finally(stmt::Block *action)
                            : utils::Element()
                            , m_action(action)
                        {
                        }
                        virtual inline ~Finally()
                        {
                        }

                        inline const stmt::Block *action() const
                        {
                            return m_action.get();
                        }
                        inline Finally &action(stmt::Block *action)
                        {
                            m_action.reset(action);
                            return *this;
                        }
                        inline stmt::Block *take_action()
                        {
                            return m_action.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<stmt::Block> m_action;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_FINALLY_H_ */
