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
        class Module;

        namespace expr
        {
            class Ident;

            namespace func
            {
                class FunctionParam;
            }
            class Function;
            class This;
            class Index;
            class Member;
            class New;
            class Call;
            class Postfix;
            class Unary;
            class Binary;
            class Condition;
            class Assign;
            class Expressions;

            namespace literal
            {
                class Null;
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

        namespace stmt
        {

            namespace decl
            {
                class Function;
                class Vars;
                class Var;
            }
            class Block;
            class ExpressionStmt;

            namespace ctrl
            {
                class If;
                class While;
                class For;
                class ForIn;
                class Continue;
                class Break;
                class Return;
                class With;
                class Switch;
                class CaseBlock;
                class Case;
                class CaseKey;
                class Label;
                class Throw;
                class Try;
                class Catch;
                class Finally;
            }
            class Debug;
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

                virtual inline void visit(const ecma::ast::Node &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Node).");
                }

                virtual inline void visit(const ecma::ast::Expression &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Expression).");
                }

                virtual inline void visit(const ecma::ast::Statement &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Statement).");
                }

                virtual inline void visit(const ecma::ast::Module &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::Module).");
                }

                virtual inline void visit(const ecma::ast::expr::Ident &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Ident).");
                }

                virtual inline void visit(const ecma::ast::expr::func::FunctionParam &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::func::FunctionParam).");
                }

                virtual inline void visit(const ecma::ast::expr::Function &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Function).");
                }

                virtual inline void visit(const ecma::ast::expr::This &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::This).");
                }

                virtual inline void visit(const ecma::ast::expr::Index &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Index).");
                }

                virtual inline void visit(const ecma::ast::expr::Member &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Member).");
                }

                virtual inline void visit(const ecma::ast::expr::New &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::New).");
                }

                virtual inline void visit(const ecma::ast::expr::Call &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Call).");
                }

                virtual inline void visit(const ecma::ast::expr::Postfix &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Postfix).");
                }

                virtual inline void visit(const ecma::ast::expr::Unary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Unary).");
                }

                virtual inline void visit(const ecma::ast::expr::Binary &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Binary).");
                }

                virtual inline void visit(const ecma::ast::expr::Condition &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Condition).");
                }

                virtual inline void visit(const ecma::ast::expr::Assign &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Assign).");
                }

                virtual inline void visit(const ecma::ast::expr::Expressions &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Expressions).");
                }

                virtual inline void visit(const ecma::ast::expr::literal::Null &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Null).");
                }

                virtual inline void visit(const ecma::ast::expr::literal::Boolean &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Boolean).");
                }

                virtual inline void visit(const ecma::ast::expr::literal::Number &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Number).");
                }

                virtual inline void visit(const ecma::ast::expr::literal::String &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::String).");
                }

                virtual inline void visit(const ecma::ast::expr::literal::Regexp &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::literal::Regexp).");
                }

                virtual inline void visit(const ecma::ast::expr::Array &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Array).");
                }

                virtual inline void visit(const ecma::ast::expr::Object &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::Object).");
                }

                virtual inline void visit(const ecma::ast::expr::object::Property &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::expr::object::Property).");
                }

                virtual inline void visit(const ecma::ast::stmt::decl::Function &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::decl::Function).");
                }

                virtual inline void visit(const ecma::ast::stmt::decl::Vars &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::decl::Vars).");
                }

                virtual inline void visit(const ecma::ast::stmt::decl::Var &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::decl::Var).");
                }

                virtual inline void visit(const ecma::ast::stmt::Block &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Block).");
                }

                virtual inline void visit(const ecma::ast::stmt::ExpressionStmt &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ExpressionStmt).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::If &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::If).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::While &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::While).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::For &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::For).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::ForIn &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::ForIn).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Continue &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Continue).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Break &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Break).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Return &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Return).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::With &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::With).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Switch &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Switch).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::CaseBlock &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::CaseBlock).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Case &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Case).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::CaseKey &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::CaseKey).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Label &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Label).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Throw &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Throw).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Try &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Try).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Catch &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Catch).");
                }

                virtual inline void visit(const ecma::ast::stmt::ctrl::Finally &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::ctrl::Finally).");
                }

                virtual inline void visit(const ecma::ast::stmt::Debug &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::stmt::Debug).");
                }

                virtual inline void visit(const ecma::ast::args::Arguments &node)
                {
                    throw std::runtime_error("Unknown AST branch (ecma::ast::args::Arguments).");
                }
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_VISITOR_H_ */
