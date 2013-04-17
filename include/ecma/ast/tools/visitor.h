#ifndef ECMA_AST_TOOLS_VISITOR_H_
#define ECMA_AST_TOOLS_VISITOR_H_

#include <stdexcept>

namespace ecma
{
    namespace ast
    {
        class Node;
        class Expression;
        class Statement;

        namespace expr
        {
            class This;
            class Array;
            class Object;
            class Identifier;
            class Assign;
            class Call;
            class Member;
            class New;
            class Index;
            class Conditional;
            class Binary;
            class Unary;

            namespace literal
            {
                class Null;
                class Undefined;
                class Boolean;
                class Integer;
                class Double;
                class Function;
                class String;
                class Regex;
            }
        }

        namespace stmt
        {
            class Block;
            class Return;
            class Continue;
            class Break;
            class With;
            class Label;
            class Throw;
            class Expression;

            namespace ctrl
            {
                class If;
                class While;
                class For;
                class ForIn;
                class Switch;
                class Try;
            }

            namespace decl
            {
                class Function;
                class Variables;
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

                virtual inline void visit(ast::Expression &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Expression).");
                }

                virtual inline void visit(ast::Statement &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Statement).");
                }

                virtual inline void visit(ast::expr::This &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::This).");
                }

                virtual inline void visit(ast::expr::Array &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Array).");
                }

                virtual inline void visit(ast::expr::Object &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Object).");
                }

                virtual inline void visit(ast::expr::Identifier &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Identifier).");
                }

                virtual inline void visit(ast::expr::Assign &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Assign).");
                }

                virtual inline void visit(ast::expr::Call &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Call).");
                }

                virtual inline void visit(ast::expr::Member &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Member).");
                }

                virtual inline void visit(ast::expr::New &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::New).");
                }

                virtual inline void visit(ast::expr::Index &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Index).");
                }

                virtual inline void visit(ast::expr::Conditional &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Conditional).");
                }

                virtual inline void visit(ast::expr::Binary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Binary).");
                }

                virtual inline void visit(ast::expr::Unary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::Unary).");
                }

                virtual inline void visit(ast::expr::literal::Null &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Null).");
                }

                virtual inline void visit(ast::expr::literal::Undefined &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Undefined).");
                }

                virtual inline void visit(ast::expr::literal::Boolean &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Boolean).");
                }

                virtual inline void visit(ast::expr::literal::Integer &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Integer).");
                }

                virtual inline void visit(ast::expr::literal::Double &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Double).");
                }

                virtual inline void visit(ast::expr::literal::Function &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Function).");
                }

                virtual inline void visit(ast::expr::literal::String &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::String).");
                }

                virtual inline void visit(ast::expr::literal::Regex &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::expr::literal::Regex).");
                }

                virtual inline void visit(ast::stmt::Block &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Block).");
                }

                virtual inline void visit(ast::stmt::Return &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Return).");
                }

                virtual inline void visit(ast::stmt::Continue &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Continue).");
                }

                virtual inline void visit(ast::stmt::Break &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Break).");
                }

                virtual inline void visit(ast::stmt::With &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::With).");
                }

                virtual inline void visit(ast::stmt::Label &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Label).");
                }

                virtual inline void visit(ast::stmt::Throw &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Throw).");
                }

                virtual inline void visit(ast::stmt::Expression &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::Expression).");
                }

                virtual inline void visit(ast::stmt::ctrl::If &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::If).");
                }

                virtual inline void visit(ast::stmt::ctrl::While &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::While).");
                }

                virtual inline void visit(ast::stmt::ctrl::For &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::For).");
                }

                virtual inline void visit(ast::stmt::ctrl::ForIn &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::ForIn).");
                }

                virtual inline void visit(ast::stmt::ctrl::Switch &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::Switch).");
                }

                virtual inline void visit(ast::stmt::ctrl::Try &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::ctrl::Try).");
                }

                virtual inline void visit(ast::stmt::decl::Function &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::decl::Function).");
                }

                virtual inline void visit(ast::stmt::decl::Variables &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::stmt::decl::Variables).");
                }

            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
