#ifndef ECMA_AST_STMT_CTRL_LABEL_H_
#define ECMA_AST_STMT_CTRL_LABEL_H_

#include <memory>
#include <string>
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
                class Label: public Statement
                {
                    public:
                        inline Label(std::string name, Statement *action)
                            : Statement()
                            , m_name(name)
                            , m_action(action)
                        {
                        }
                        virtual inline ~Label()
                        {
                        }

                        inline const std::string name() const
                        {
                            return m_name;
                        }
                        inline Label &name(std::string name)
                        {
                            m_name = name;
                            return *this;
                        }

                        inline const Statement *action() const
                        {
                            return m_action.get();
                        }
                        inline Label &action(Statement *action)
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
                        std::string m_name;
                        std::unique_ptr<Statement> m_action;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_LABEL_H_ */
