#ifndef ECMA_AST_EXPR_LITERAL_NULL_H_
#define ECMA_AST_EXPR_LITERAL_NULL_H_

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
                class Null: public Expression
                {
                    public:
                        inline Null()
                            : Expression()
                        {
                        }
                        virtual inline ~Null()
                        {
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_NULL_H_ */
