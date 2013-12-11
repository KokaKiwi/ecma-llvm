#ifndef ECMA_AST_TOOLS_VISITOR_H_
#define ECMA_AST_TOOLS_VISITOR_H_

namespace ecma
{
    namespace ast
    {
        class Node;
        class Expression;
        class Statement;

        namespace stmt
        {
            class IfStatement;
        }

        namespace expr
        {
            class FunctionCall;
        }

        namespace tools
        {
            class Visitor
            {
            public:
                inline ~Visitor() {}

                virtual inline void visit(ecma::ast::Node &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Node).");
                }

                virtual inline void visit(ecma::ast::Expression &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Expression).");
                }

                virtual inline void visit(ecma::ast::Statement &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Statement).");
                }

                virtual inline void visit(ecma::ast::stmt::IfStatement &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::IfStatement).");
                }

                virtual inline void visit(ecma::ast::expr::FunctionCall &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::FunctionCall).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
