#ifndef ECMA_AST_EXPR_OBJECT_H_
#define ECMA_AST_EXPR_OBJECT_H_

#include "ecma/ast/statement.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Object: public ast::Statement
            {
            public:
                inline Object() {}

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_OBJECT_H_ */
