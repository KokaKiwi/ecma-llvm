#include <stdexcept>

#ifndef ECMA_AST_TOOLS_VISITOR_H_
#define ECMA_AST_TOOLS_VISITOR_H_

namespace ecma
{
    namespace ast
    {
        class Node;
        class Expression;
        class Statement;

        namespace expr
        {

            namespace literal
            {
                class Null;
                class Undefined;
                class Boolean;
                class Number;
                class String;
                class Regexp;
            }
            class Array;
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

                virtual inline void visit(ecma::ast::expr::literal::Null &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Null).");
                }

                virtual inline void visit(ecma::ast::expr::literal::Undefined &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Undefined).");
                }

                virtual inline void visit(ecma::ast::expr::literal::Boolean &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Boolean).");
                }

                virtual inline void visit(ecma::ast::expr::literal::Number &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Number).");
                }

                virtual inline void visit(ecma::ast::expr::literal::String &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::String).");
                }

                virtual inline void visit(ecma::ast::expr::literal::Regexp &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Regexp).");
                }

                virtual inline void visit(ecma::ast::expr::Array &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Array).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
