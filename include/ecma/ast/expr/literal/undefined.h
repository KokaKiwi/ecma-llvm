#ifndef ECMA_AST_EXPR_LITERAL_UNDEFINED_H_
#define ECMA_AST_EXPR_LITERAL_UNDEFINED_H_

#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Undefined: public ast::Expression
                {
                public:
                    inline Undefined() {}

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_UNDEFINED_H_ */
