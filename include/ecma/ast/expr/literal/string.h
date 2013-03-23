#ifndef ECMA_AST_EXPR_LITERAL_STRING_H_
#define ECMA_AST_EXPR_LITERAL_STRING_H_

#include <string>
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
                class String: public ast::Expression
                {
                public:
                    String(const std::string &value): m_value(value) {}

                    inline String &replace(const std::string &oldStr, const std::string &newStr)
                    {
                        std::string::size_type pos;
                        while ((pos = m_value.find(oldStr, pos)) != std::string::npos)
                        {
                            m_value.replace(pos, oldStr.length(), newStr);
                            pos += newStr.length();
                        }

                        return *this;
                    }

                    inline String &escape(void)
                    {
                        replace("\\n", "\n");
                        replace("\\t", "\t");

                        return *this;
                    }

                    inline const std::string &value(void) const
                    {
                        return m_value;
                    }
                    inline String &value(const std::string &value)
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
