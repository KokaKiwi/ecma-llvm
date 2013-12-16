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

        namespace stmt
        {
            class Block;

            namespace decl
            {
                class Vars;
                class Var;
            }
            class ExpressionStmt;
            class If;
            class While;
            class For;
            class ForIn;
            class Continue;
            class Break;
            class Return;
            class With;
            class Switch;
            class Label;
            class Throw;
            class Debug;
        }

        namespace expr
        {
            class This;
            class Ident;
            class Index;
            class Member;
            class New;
            class Call;
            class Postfix;
            class Unary;
            class Binary;
            class Condition;
            class Assign;

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
            class Object;

            namespace object
            {
                class Property;
            }
        }

        namespace args
        {
            class Arguments;
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

                virtual inline void visit(ecma::ast::stmt::Block &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Block).");
                }

                virtual inline void visit(ecma::ast::stmt::decl::Vars &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::decl::Vars).");
                }

                virtual inline void visit(ecma::ast::stmt::decl::Var &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::decl::Var).");
                }

                virtual inline void visit(ecma::ast::stmt::ExpressionStmt &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ExpressionStmt).");
                }

                virtual inline void visit(ecma::ast::stmt::If &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::If).");
                }

                virtual inline void visit(ecma::ast::stmt::While &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::While).");
                }

                virtual inline void visit(ecma::ast::stmt::For &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::For).");
                }

                virtual inline void visit(ecma::ast::stmt::ForIn &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ForIn).");
                }

                virtual inline void visit(ecma::ast::stmt::Continue &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Continue).");
                }

                virtual inline void visit(ecma::ast::stmt::Break &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Break).");
                }

                virtual inline void visit(ecma::ast::stmt::Return &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Return).");
                }

                virtual inline void visit(ecma::ast::stmt::With &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::With).");
                }

                virtual inline void visit(ecma::ast::stmt::Switch &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Switch).");
                }

                virtual inline void visit(ecma::ast::stmt::Label &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Label).");
                }

                virtual inline void visit(ecma::ast::stmt::Throw &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Throw).");
                }

                virtual inline void visit(ecma::ast::stmt::Debug &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Debug).");
                }

                virtual inline void visit(ecma::ast::expr::This &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::This).");
                }

                virtual inline void visit(ecma::ast::expr::Ident &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Ident).");
                }

                virtual inline void visit(ecma::ast::expr::Index &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Index).");
                }

                virtual inline void visit(ecma::ast::expr::Member &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Member).");
                }

                virtual inline void visit(ecma::ast::expr::New &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::New).");
                }

                virtual inline void visit(ecma::ast::expr::Call &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Call).");
                }

                virtual inline void visit(ecma::ast::expr::Postfix &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Postfix).");
                }

                virtual inline void visit(ecma::ast::expr::Unary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Unary).");
                }

                virtual inline void visit(ecma::ast::expr::Binary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Binary).");
                }

                virtual inline void visit(ecma::ast::expr::Condition &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Condition).");
                }

                virtual inline void visit(ecma::ast::expr::Assign &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Assign).");
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

                virtual inline void visit(ecma::ast::expr::Object &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Object).");
                }

                virtual inline void visit(ecma::ast::expr::object::Property &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::object::Property).");
                }

                virtual inline void visit(ecma::ast::args::Arguments &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::args::Arguments).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
