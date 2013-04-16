#ifndef ECMA_AST_EXPR_THIS_H_
#define ECMA_AST_EXPR_THIS_H_

#include "ecma/ast/statement.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class This: public ast::Statement
            {
            public:
                inline This() {}

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_THIS_H_ */
