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
            class Expression;
            class Return;

            namespace decl
            {
                class Variables;
            }
        }

        namespace expr
        {
            class Binary;
            class Unary;
            class Assignment;

            namespace literal
            {
                class Number;
                class Identifier;
                class FunctionCall;
                class String;
            }
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

                virtual inline void visit(ast::stmt::Expression &expr)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Expression).");
                }

                virtual inline void visit(ast::stmt::decl::Variables &vars)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::decl::Variables).");
                }

                virtual inline void visit(ast::expr::Binary &binary)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Binary).");
                }

                virtual inline void visit(ast::expr::Unary &unary)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Unary).");
                }

                virtual inline void visit(ast::expr::Assignment &assign)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Assignment).");
                }

                virtual inline void visit(ast::expr::literal::Number &number)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Number).");
                }

                virtual inline void visit(ast::expr::literal::Identifier &identifier)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Identifier).");
                }

                virtual inline void visit(ast::expr::literal::FunctionCall &call)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::FunctionCall).");
                }

                virtual inline void visit(ast::expr::literal::String &string)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::String).");
                }

                virtual inline void visit(ast::stmt::Return &ret)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Return).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
