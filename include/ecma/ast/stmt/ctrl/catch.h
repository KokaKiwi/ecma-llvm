#ifndef ECMA_AST_STMT_CTRL_CATCH_H_
#define ECMA_AST_STMT_CTRL_CATCH_H_

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
                class Catch: public utils::Element
                {
                    public:
                        inline Catch(std::string name, stmt::Block *action)
                            : utils::Element()
                            , m_name(name)
                            , m_action(action)
                        {
                        }
                        virtual inline ~Catch()
                        {
                        }

                        inline const std::string name() const
                        {
                            return m_name;
                        }
                        inline Catch &name(std::string name)
                        {
                            m_name = name;
                            return *this;
                        }

                        inline const stmt::Block *action() const
                        {
                            return m_action.get();
                        }
                        inline Catch &action(stmt::Block *action)
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
                        std::string m_name;
                        std::unique_ptr<stmt::Block> m_action;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_CATCH_H_ */
