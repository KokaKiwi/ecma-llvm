#ifndef ECMA_AST_TOOLS_PRINT_VISITOR_H_
#define ECMA_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/ast/stmt/expression.h"
#include "ecma/ast/stmt/decl/variables.h"
#include "ecma/ast/expr/unary.h"
#include "ecma/ast/expr/binary.h"
#include "ecma/ast/expr/assignment.h"
#include "ecma/ast/expr/literal/number.h"
#include "ecma/ast/expr/literal/identifier.h"
#include "ecma/ast/expr/literal/function_call.h"
#include "ecma/ast/expr/literal/string.h"

namespace ecma
{
    namespace ast
    {
        namespace tools
        {
            class PrintVisitor: public ast::tools::Visitor
            {
            public:
                PrintVisitor(): depth(0) {}

                inline void visit(ast::stmt::Block &block)
                {
                    std::cout << spaces() << "Block:" << std::endl;
                    for (ast::Statement *stmt : block.statements())
                    {
                        depth++;
                        stmt->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::decl::Variables &vars)
                {
                    for (ast::stmt::decl::Variables::Variable *var : vars.variables())
                    {
                        std::cout << spaces() << "Variable: " << var->name() << std::endl;

                        if (var->initializer())
                        {
                            depth++;
                            var->initializer()->accept(*this);
                            depth--;
                        }
                    }
                }

                inline void visit(ast::expr::Assignment &assign)
                {
                    std::cout << spaces() << "Assign: " << assign.name() << std::endl;

                    if (assign.value())
                    {
                        depth++;
                        assign.value()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::Expression &expr)
                {
                    std::cout << spaces() << "Expression:" << std::endl;
                    if (expr.expr())
                    {
                        depth++;
                        expr.expr()->accept(*this);
                        depth--;
                    }
                    else
                    {
                        std::cout << spaces() << "  Null expression" << std::endl;
                    }
                }

                inline void visit(ast::expr::Unary &unary)
                {
                    std::cout << spaces() << "Unary: ";
                    switch (unary.op())
                    {
                        case ast::expr::Unary::Operator::Not: std::cout << "Not"; break;
                        case ast::expr::Unary::Operator::Inv: std::cout << "Inv"; break;
                        case ast::expr::Unary::Operator::Positive: std::cout << "Positive"; break;
                        case ast::expr::Unary::Operator::Negative: std::cout << "Negative"; break;
                    }
                    std::cout << std::endl;

                    depth++;
                    unary.expr()->accept(*this);
                    depth--;
                }

                inline void visit(ast::expr::Binary &binary)
                {
                    std::cout << spaces() << "Binary: ";
                    switch (binary.op())
                    {
                        case ast::expr::Binary::Operator::Addition: std::cout << "Addition"; break;
                        case ast::expr::Binary::Operator::Substraction: std::cout << "Substraction"; break;
                        case ast::expr::Binary::Operator::Multiplication: std::cout << "Multiplication"; break;
                        case ast::expr::Binary::Operator::Division: std::cout << "Division"; break;
                        case ast::expr::Binary::Operator::Modulo: std::cout << "Modulo"; break;
                    }
                    std::cout << std::endl;

                    if (binary.left())
                    {
                        depth++;
                        std::cout << spaces() << "Left:" << std::endl;
                        depth++;
                        binary.left()->accept(*this);
                        depth--;
                        depth--;
                    }

                    if (binary.right())
                    {
                        depth++;
                        std::cout << spaces() << "Right:" << std::endl;
                        depth++;
                        binary.right()->accept(*this);
                        depth--;
                        depth--;
                    }
                }

                inline void visit(ast::expr::literal::Number &number)
                {
                    std::cout << spaces() << "Number: " << number.value() << std::endl;
                }

                inline void visit(ast::expr::literal::Identifier &identifier)
                {
                    std::cout << spaces() << "Identifier: " << identifier.name() << std::endl;
                }

                inline void visit(ast::expr::literal::FunctionCall &call)
                {
                    std::cout << spaces() << "Function call: " << call.name() << std::endl;

                    if (call.arguments())
                    {
                        for (ast::Expression *arg : *call.arguments())
                        {
                            depth++;
                            arg->accept(*this);
                            depth--;
                        }
                    }
                }

                inline void visit(ast::expr::literal::String &string)
                {
                    std::cout << spaces() << "String: '" << string.value() << "'" << std::endl;
                }

            private:
                inline std::string spaces()
                {
                    std::stringstream stream;

                    for (int i = 0; i < depth; i++)
                    {
                        stream << "  ";
                    }

                    return stream.str();
                }

                int depth;
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_PRINT_VISITOR_H_ */
