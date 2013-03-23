#ifndef ECMA_AST_NODE_H_
#define ECMA_AST_NODE_H_

namespace ecma
{
    namespace ast
    {
        namespace tools
        {
            class Visitor;
        }

        class Node
        {
        public:
            virtual ~Node() {}

            virtual void accept(ast::tools::Visitor &visitor) = 0;
        };
    }
}

#endif /* ECMA_AST_NODE_H_ */
