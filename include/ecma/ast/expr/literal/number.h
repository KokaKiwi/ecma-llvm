#ifndef ECMA_AST_EXPR_LITERAL_NUMBER_H_
#define ECMA_AST_EXPR_LITERAL_NUMBER_H_

#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Number: public ast::Expression
                {
                public:
                    typedef int value_type;

                    Number(value_type value): m_value(value) {}

                    inline value_type value(void) const
                    {
                        return m_value;
                    }
                    inline Number &value(value_type value)
                    {
                        m_value = value;
                        return *this;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    value_type m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_NUMBER_H_ */
