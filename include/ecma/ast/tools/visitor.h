#ifndef ECMA_AST_TOOLS_VISITOR_H_
#define ECMA_AST_TOOLS_VISITOR_H_

#include <stdexcept>

namespace ecma
{
    namespace ast
    {
        class Node;
        class Statement;
        class Expression;

        namespace stmt
        {
            class Block;
        }

        namespace tools
        {
            class Visitor
            {
            public:
                inline ~Visitor() {}

                virtual inline void visit(ast::Node &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Node).");
                }

                virtual inline void visit(ast::Statement &statement)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Statement).");
                }

                virtual inline void visit(ast::Expression &expr)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Expression).");
                }

                virtual inline void visit(ast::stmt::Block &block)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Block).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
