#ifndef ECMA_AST_EXPR_LITERAL_REGEXP_H_
#define ECMA_AST_EXPR_LITERAL_REGEXP_H_

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
                class Regexp: public Expression
                {
                    public:
                        inline Regexp(std::string value)
                            : Expression()
                            , m_value(value)
                        {
                        }
                        virtual inline ~Regexp()
                        {
                        }

                        inline const std::string value() const
                        {
                            return m_value;
                        }
                        inline Regexp &value(std::string value)
                        {
                            m_value = value;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
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

#endif /* ECMA_AST_EXPR_LITERAL_REGEXP_H_ */
