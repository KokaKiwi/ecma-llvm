#ifndef ECMA_AST_EXPRESSION_H_
#define ECMA_AST_EXPRESSION_H_

#include "ecma/ast/node.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        class Expression: public Node
        {
            public:
                inline Expression()
                    : Node()
                {
                }
                virtual inline ~Expression()
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

#endif /* ECMA_AST_EXPRESSION_H_ */
