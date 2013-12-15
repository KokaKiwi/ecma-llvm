#ifndef ECMA_AST_NODE_H_
#define ECMA_AST_NODE_H_

#include "ecma/utils/element.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        class Node: public utils::Element
        {
            public:
                inline Node()
                    : utils::Element()
                {}

                inline void accept(tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
        };
    }
}

#endif /* ECMA_AST_NODE_H_ */
