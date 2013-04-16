#ifndef ECMA_AST_EXPR_ARRAY_H_
#define ECMA_AST_EXPR_ARRAY_H_

#include "ecma/ast/statement.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Array: public ast::Statement
            {
            public:
                inline Array() {}

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_ARRAY_H_ */
