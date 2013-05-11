#ifndef ECMA_AST_EXPR_LITERAL_STRING_H_
#define ECMA_AST_EXPR_LITERAL_STRING_H_

#include <string>
#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class String: public ast::Expression
                {
                public:
                    inline String(const std::string &value): m_value(value.substr(1, value.length() - 2))
                    {
                        clean();
                    }

                    inline void replace(const std::string &from, const std::string &to)
                    {
                        size_t start_pos = 0;

                        while ((start_pos = m_value.find(from, start_pos)) != std::string::npos)
                        {
                            m_value.replace(start_pos, from.length(), to);
                            start_pos += to.length();
                        }
                    }

                    inline void clean()
                    {
                        replace("\\n", "\n");
                        replace("\\t", "\t");
                    }

                    inline const std::string &value(void) const
                    {
                        return m_value;
                    }
                    inline String &value(std::string &value)
                    {
                        m_value = value;
                        return *this;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_STRING_H_ */
