#ifndef ECMA_AST_EXPR_LITERAL_UNDEFINED_H_
#define ECMA_AST_EXPR_LITERAL_UNDEFINED_H_

#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Undefined: public Expression
                {
                    public:
                        inline Undefined()
                            : Expression()
                        {
                        }
                        inline ~Undefined()
                        {
                        }

                        inline void accept(tools::Visitor &visitor)
                        {
                            visitor.visit(*this);
                        }

                    private:
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_UNDEFINED_H_ */
