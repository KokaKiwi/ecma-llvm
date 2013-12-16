#ifndef ECMA_AST_STMT_LABEL_H_
#define ECMA_AST_STMT_LABEL_H_

#include <string>
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Label: public Statement
            {
                public:
                    inline Label(std::string name, Statement *action)
                        : Statement()
                        , m_name(name)
                        , m_action(action)
                    {}

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
                    inline Statement *action()
                    {
                        return m_action.release();
                    }

                    inline void accept(tools::Visitor &visitor)
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

#endif /* ECMA_AST_STMT_LABEL_H_ */
