#ifndef ECMA_AST_EXPR_LITERAL_DOUBLE_H_
#define ECMA_AST_EXPR_LITERAL_DOUBLE_H_

#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Double: public ast::Expression
                {
                public:
                    inline Double(double value): m_value(value) {}

                    inline const double value(void) const
                    {
                        return m_value;
                    }
                    inline ecma::ast::expr::literal::Double &value(double value)
                    {
                        m_value = value;
                        return *this;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    double m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_DOUBLE_H_ */
