#ifndef ECMA_AST_EXPR_FUNCTION_H_
#define ECMA_AST_EXPR_FUNCTION_H_

#include <string>
#include <vector>
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Function: public Expression
            {
                public:
                    inline Function(std::string name)
                        : Expression()
                        , m_name(name)
                    {
                    }
                    virtual inline ~Function()
                    {
                    }

                    inline const std::string name() const
                    {
                        return m_name;
                    }
                    inline Function &name(std::string name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline const std::vector<std::string> &args() const
                    {
                        return m_args;
                    }
                    inline std::vector<std::string> &args()
                    {
                        return m_args;
                    }

                    inline const std::vector<std::unique_ptr<Statement>> &body() const
                    {
                        return m_body;
                    }
                    inline std::vector<std::unique_ptr<Statement>> &body()
                    {
                        return m_body;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_name;
                    std::vector<std::string> m_args;
                    std::vector<std::unique_ptr<Statement>> m_body;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_FUNCTION_H_ */
