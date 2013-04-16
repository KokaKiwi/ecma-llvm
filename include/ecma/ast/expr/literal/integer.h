#ifndef ECMA_AST_EXPR_LITERAL_INTEGER_H_
#define ECMA_AST_EXPR_LITERAL_INTEGER_H_

#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Integer: public ast::Expression
                {
                public:
                    inline Integer(int value): m_value(value) {}

                    inline const int value(void) const
                    {
                        return m_value;
                    }
                    inline ecma::ast::expr::literal::Integer &value(int value)
                    {
                        m_value = value;
                        return *this;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    int m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_INTEGER_H_ */
