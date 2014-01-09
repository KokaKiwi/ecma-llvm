#ifndef ECMA_AST_EXPR_FUNCTION_H_
#define ECMA_AST_EXPR_FUNCTION_H_

#include <vector>
#include <memory>
#include <string>
#include "ecma/ast/expression.h"
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
                        , m_native(false)
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

                    inline const std::vector<std::unique_ptr<expr::func::FunctionParam>> &args() const
                    {
                        return m_args;
                    }
                    inline std::vector<std::unique_ptr<expr::func::FunctionParam>> &args()
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

                    inline const std::string ret_type() const
                    {
                        return m_ret_type;
                    }
                    inline Function &ret_type(std::string ret_type)
                    {
                        m_ret_type = ret_type;
                        return *this;
                    }

                    inline const bool native() const
                    {
                        return m_native;
                    }
                    inline Function &native(bool native)
                    {
                        m_native = native;
                        return *this;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_name;
                    std::vector<std::unique_ptr<expr::func::FunctionParam>> m_args;
                    std::vector<std::unique_ptr<Statement>> m_body;
                    std::string m_ret_type;
                    bool m_native;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_FUNCTION_H_ */
