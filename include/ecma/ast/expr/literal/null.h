#ifndef ECMA_AST_EXPR_LITERAL_NULL_H_
#define ECMA_AST_EXPR_LITERAL_NULL_H_

#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Null: public ast::Expression
                {
                public:
                    inline Null() {}

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_NULL_H_ */
