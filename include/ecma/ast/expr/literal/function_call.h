#ifndef ECMA_AST_EXPR_LITERAL_FUNCTION_CALL_H_
#define ECMA_AST_EXPR_LITERAL_FUNCTION_CALL_H_

#include <string>
#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class FunctionCall: public ast::Expression
                {
                public:
                    using Arguments = std::vector<ast::Expression *>;

                    FunctionCall(const std::string &name, Arguments *arguments = nullptr): m_name(name), m_arguments(arguments) {}
                    ~FunctionCall()
                    {
                        if (m_arguments)
                        {
                            for (ast::Expression *expr : *m_arguments)
                            {
                                delete expr;
                            }
                        }
                    }

                    inline const std::string &name(void) const
                    {
                        return m_name;
                    }
                    inline FunctionCall &name(const std::string &name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline Arguments *arguments(void) const
                    {
                        return m_arguments.get();
                    }
                    inline FunctionCall &arguments(Arguments *arguments)
                    {
                        m_arguments.reset(arguments);
                        return *this;
                    }
                    inline Arguments *takeArguments(void)
                    {
                        return m_arguments.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_name;
                    std::unique_ptr<Arguments> m_arguments;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_FUNCTION_CALL_H_ */
