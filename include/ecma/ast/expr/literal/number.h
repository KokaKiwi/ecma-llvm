#ifndef ECMA_AST_EXPR_LITERAL_NUMBER_H_
#define ECMA_AST_EXPR_LITERAL_NUMBER_H_

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
                class Number: public Expression
                {
                    public:
                        inline Number(std::string value)
                            : Expression()
                            , m_value(value)
                        {
                        }
                        virtual inline ~Number()
                        {
                        }

                        inline const std::string value() const
                        {
                            return m_value;
                        }
                        inline Number &value(std::string value)
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

#endif /* ECMA_AST_EXPR_LITERAL_NUMBER_H_ */
