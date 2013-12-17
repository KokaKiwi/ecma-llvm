#ifndef ECMA_AST_EXPR_LITERAL_STRING_H_
#define ECMA_AST_EXPR_LITERAL_STRING_H_

#include <string>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class String: public Expression
                {
                    public:
                        inline String(std::string value)
                            : Expression()
                            , m_value(value)
                        {
                        }
                        virtual inline ~String()
                        {
                        }

                        inline const std::string value() const
                        {
                            return m_value;
                        }
                        inline String &value(std::string value)
                        {
                            m_value = value;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor)
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
