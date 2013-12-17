#ifndef ECMA_AST_STATEMENT_H_
#define ECMA_AST_STATEMENT_H_

#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        class Statement: public Node
        {
            public:
                inline Statement()
                    : Node()
                {
                }
                virtual inline ~Statement()
                {
                }

                virtual inline void accept(tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
        };
    }
}

#endif /* ECMA_AST_STATEMENT_H_ */
