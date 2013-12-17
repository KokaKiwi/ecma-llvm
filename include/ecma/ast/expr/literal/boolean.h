#ifndef ECMA_AST_EXPR_LITERAL_BOOLEAN_H_
#define ECMA_AST_EXPR_LITERAL_BOOLEAN_H_

#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Boolean: public Expression
                {
                    public:
                        inline Boolean(bool value)
                            : Expression()
                            , m_value(value)
                        {
                        }
                        virtual inline ~Boolean()
                        {
                        }

                        inline const bool value() const
                        {
                            return m_value;
                        }
                        inline Boolean &value(bool value)
                        {
                            m_value = value;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor)
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
