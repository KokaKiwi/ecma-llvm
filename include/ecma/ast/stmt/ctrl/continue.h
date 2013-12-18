#ifndef ECMA_AST_STMT_CTRL_CONTINUE_H_
#define ECMA_AST_STMT_CTRL_CONTINUE_H_

#include <string>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Continue: public Statement
                {
                    public:
                        inline Continue()
                            : Statement()
                        {
                        }
                        virtual inline ~Continue()
                        {
                        }

                        inline const std::string name() const
                        {
                            return m_name;
                        }
                        inline Continue &name(std::string name)
                        {
                            m_name = name;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::string m_name;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_CONTINUE_H_ */
