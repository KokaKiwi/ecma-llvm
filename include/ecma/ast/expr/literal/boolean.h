#ifndef ECMA_AST_EXPR_LITERAL_BOOLEAN_H_
#define ECMA_AST_EXPR_LITERAL_BOOLEAN_H_

#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Boolean: public ast::Expression
                {
                public:
                    inline Boolean(bool value): m_value(value) {}

                    inline const bool value(void) const
                    {
                        return m_value;
                    }
                    inline ecma::ast::expr::literal::Boolean &value(bool value)
                    {
                        m_value = value;
                        return *this;
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    bool m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_BOOLEAN_H_ */
