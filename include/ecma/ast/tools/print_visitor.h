#ifndef ECMA_AST_TOOLS_PRINT_VISITOR_H_
#define ECMA_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace tools
        {
            class PrintVisitor: public ast::tools::Visitor
            {
            public:
                PrintVisitor(std::ostream &stream): depth(0), m_stream(stream) {}

                inline void visit(ast::stmt::Block &block)
                {
                    stream() << spaces() << "Block:" << std::endl;
                    for (ast::Statement *stmt : block.statements())
                    {
                        if (stmt)
                        {
                            depth++;
                            stmt->accept(*this);
                            depth--;
                        }
                    }
                }

                inline void visit(ast::stmt::decl::Variables &vars)
                {
                    stream() << spaces() << "Variables:" << std::endl;
                    for (ast::stmt::decl::Variables::Variable *var : vars.vars())
                    {
                        if (var)
                        {
                            depth++;
                            stream() << spaces() << "Variable: " << var->name() << std::endl;
                            if (var->initializer())
                            {
                                depth++;
                                var->initializer()->accept(*this);
                                depth--;
                            }
                            depth--;
                        }
                    }
                }

                inline void visit(ast::stmt::decl::Function &function)
                {
                    stream() << spaces() << "Named function: " << function.name() << std::endl;
                    if (function.literal())
                    {
                        depth++;
                        function.literal()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::ctrl::If &stmt)
                {
                    stream() << spaces() << "If:" << std::endl;
                    if (stmt.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        stmt.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (stmt.thenBranch())
                    {
                        depth++;
                        stream() << spaces() << "Then:" << std::endl;
                        depth++;
                        stmt.thenBranch()->accept(*this);
                        depth -= 2;
                    }
                    if (stmt.elseBranch())
                    {
                        depth++;
                        stream() << spaces() << "Else:" << std::endl;
                        depth++;
                        stmt.elseBranch()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::ctrl::While &loop)
                {
                    stream() << spaces() << (loop.doFirst() ? "Do:" : "While:") << std::endl;
                    if (loop.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        loop.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (loop.thenBranch())
                    {
                        depth++;
                        stream() << spaces() << "Then:" << std::endl;
                        depth++;
                        loop.thenBranch()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::ctrl::For &loop)
                {
                    stream() << spaces() << "For:" << std::endl;
                    if (loop.initializer())
                    {
                        depth++;
                        stream() << spaces() << "Initializer:" << std::endl;
                        depth++;
                        loop.initializer()->accept(*this);
                        depth -= 2;
                    }
                    if (loop.condBranch())
                    {
                        depth++;
                        stream() << spaces() << "Condition:" << std::endl;
                        depth++;
                        loop.condBranch()->accept(*this);
                        depth -= 2;
                    }
                    if (loop.loopBranch())
                    {
                        depth++;
                        stream() << spaces() << "Loop:" << std::endl;
                        depth++;
                        loop.loopBranch()->accept(*this);
                        depth -= 2;
                    }
                    if (loop.thenBranch())
                    {
                        depth++;
                        stream() << spaces() << "Then:" << std::endl;
                        depth++;
                        loop.thenBranch()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::ctrl::ForIn &loop)
                {
                    stream() << spaces() << "ForIn: " << (loop.decl() ? "var " : "") << loop.name() << std::endl;
                    if (loop.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        loop.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (loop.thenBranch())
                    {
                        depth++;
                        stream() << spaces() << "Then:" << std::endl;
                        depth++;
                        loop.thenBranch()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::ctrl::Switch &node)
                {
                    stream() << spaces() << "Switch:" << std::endl;
                    if (node.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        node.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (node.caseblock())
                    {
                        depth++;
                        stream() << spaces() << "Case blocks:" << std::endl;
                        for (ast::stmt::ctrl::Switch::Case *clause : *node.caseblock())
                        {
                            depth++;
                            stream() << spaces() << "Case:" << std::endl;
                            if (clause->key())
                            {
                                depth++;
                                stream() << spaces() << "Expression:" << std::endl;
                                depth++;
                                clause->key()->accept(*this);
                                depth -= 2;
                            }
                            if (clause->block())
                            {
                                depth++;
                                clause->block()->accept(*this);
                                depth--;
                            }
                            depth--;
                        }
                        depth--;
                    }
                }

                inline void visit(ast::stmt::ctrl::Try &node)
                {
                    stream() << spaces() << "Try:" << std::endl;
                    if (node.block())
                    {
                        depth++;
                        stream() << spaces() << "Block:" << std::endl;
                        depth++;
                        node.block()->accept(*this);
                        depth -= 2;
                    }
                    if (node.catchBranch())
                    {
                        depth++;
                        stream() << spaces() << "Catch: " << node.catchBranch()->name() << std::endl;
                        depth++;
                        node.catchBranch()->block()->accept(*this);
                        depth -= 2;
                    }
                    if (node.finallyBranch())
                    {
                        depth++;
                        stream() << spaces() << "Finally:" << std::endl;
                        depth++;
                        node.finallyBranch()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Assign &assign)
                {
                    stream() << spaces() << "Assign: " << assign.type() << std::endl;
                    if (assign.left())
                    {
                        depth++;
                        stream() << spaces() << "Left:" << std::endl;
                        depth++;
                        assign.left()->accept(*this);
                        depth -= 2;
                    }
                    if (assign.expr())
                    {
                        depth++;
                        stream() << spaces() << "Right:" << std::endl;
                        depth++;
                        assign.expr()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Binary &binary)
                {
                    stream() << spaces() << "Binary: " << binary.type() << std::endl;
                    if (binary.left())
                    {
                        depth++;
                        stream() << spaces() << "Left:" << std::endl;
                        depth++;
                        binary.left()->accept(*this);
                        depth -= 2;
                    }
                    if (binary.right())
                    {
                        depth++;
                        stream() << spaces() << "Right:" << std::endl;
                        depth++;
                        binary.right()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Conditional &cond)
                {
                    stream() << spaces() << "Conditional:" << std::endl;
                    if (cond.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        cond.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (cond.thenExpr())
                    {
                        depth++;
                        stream() << spaces() << "Then:" << std::endl;
                        depth++;
                        cond.thenExpr()->accept(*this);
                        depth -= 2;
                    }
                    if (cond.elseExpr())
                    {
                        depth++;
                        stream() << spaces() << "Else:" << std::endl;
                        depth++;
                        cond.elseExpr()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Unary &unary)
                {
                    stream() << spaces() << "Unary: " << unary.type() << std::endl;
                    if (unary.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        unary.expr()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::Return &ret)
                {
                    stream() << spaces() << "Return:" << std::endl;
                    if (ret.expr())
                    {
                        depth++;
                        ret.expr()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::Continue &cont)
                {
                    stream() << spaces() << "Continue: " << cont.name() << std::endl;
                }

                inline void visit(ast::stmt::Break &br)
                {
                    if (br.name().length() > 0)
                    {
                        stream() << spaces() << "Break: " << br.name() << std::endl;
                    }
                    else
                    {
                        stream() << spaces() << "Break" << std::endl;
                    }
                }

                inline void visit(ast::stmt::With &with)
                {
                    stream() << spaces() << "With:" << std::endl;
                    if (with.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        with.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (with.stmt())
                    {
                        depth++;
                        stream() << spaces() << "Statement:" << std::endl;
                        depth++;
                        with.stmt()->accept(*this);
                        depth -= 2;
                    }
                }

                inline void visit(ast::stmt::Throw &raise)
                {
                    stream() << spaces() << "Throw:" << std::endl;
                    if (raise.expr())
                    {
                        depth++;
                        raise.expr()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::Label &label)
                {
                    stream() << spaces() << "Label: " << label.name() << std::endl;
                    if (label.stmt())
                    {
                        depth++;
                        label.stmt()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::stmt::Expression &expr)
                {
                    stream() << spaces() << "Expression:" << std::endl;
                    if (expr.expr())
                    {
                        depth++;
                        expr.expr()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::expr::literal::Boolean &boolean)
                {
                    stream() << spaces() << "Boolean: " << (boolean.value() ? "true" : "false") << std::endl;
                }

                inline void visit(ast::expr::literal::Double &num)
                {
                    stream() << spaces() << "Double: " << num.value() << std::endl;
                }

                inline void visit(ast::expr::literal::String &string)
                {
                    stream() << spaces() << "String: \"" << string.value() << "\"" << std::endl;
                }

                inline void visit(ast::expr::literal::Regex &regex)
                {
                    stream() << spaces() << "Regex: /" << regex.value() << "/" << std::endl;
                }

                inline void visit(ast::expr::literal::Integer &num)
                {
                    stream() << spaces() << "Integer: " << num.value() << std::endl;
                }

                inline void visit(ast::expr::literal::Null &null)
                {
                    stream() << spaces() << "Null" << std::endl;
                }

                inline void visit(ast::expr::literal::Undefined &node)
                {
                    stream() << spaces() << "Undefined" << std::endl;
                }

                inline void visit(ast::expr::literal::Function &function)
                {
                    stream() << spaces() << "Function:";
                    if (function.args())
                    {
                        for (std::string arg : *function.args())
                        {
                            stream() << " " << arg;
                        }
                    }
                    stream() << std::endl;
                    if (function.block())
                    {
                        depth++;
                        function.block()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::expr::Object &object)
                {
                    stream() << spaces() << "Object:" << std::endl;
                    if (object.properties())
                    {
                        for (ast::expr::Object::Property *property : *object.properties())
                        {
                            depth++;
                            stream() << spaces() << "Property: " << *property->key() << std::endl;
                            depth++;
                            property->value()->accept(*this);
                            depth -= 2;
                        }
                    }
                }

                inline void visit(ast::expr::Array &array)
                {
                    stream() << spaces() << "Array:" << std::endl;
                    if (array.values())
                    {
                        for (ast::Expression *value : *array.values())
                        {
                            depth++;
                            value->accept(*this);
                            depth--;
                        }
                    }
                }

                inline void visit(ast::expr::Identifier &identifier)
                {
                    stream() << spaces() << "Identifier: " << identifier.name() << std::endl;
                }

                inline void visit(ast::expr::This &node)
                {
                    stream() << spaces() << "This" << std::endl;
                }

                inline void visit(ast::expr::Call &call)
                {
                    stream() << spaces() << "Call:" << std::endl;
                    if (call.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        call.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (call.args())
                    {
                        depth++;
                        stream() << spaces() << "Arguments:" << std::endl;
                        depth++;
                        for (ast::Expression *arg : *call.args())
                        {
                            arg->accept(*this);
                        }
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Member &member)
                {
                    stream() << spaces() << "Member: " << member.name() << std::endl;
                    if (member.expr())
                    {
                        depth++;
                        member.expr()->accept(*this);
                        depth--;
                    }
                }

                inline void visit(ast::expr::New &node)
                {
                    stream() << spaces() << "New:" << std::endl;
                    if (node.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        node.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (node.args())
                    {
                        depth++;
                        stream() << spaces() << "Arguments:" << std::endl;
                        depth++;
                        for (ast::Expression *arg : *node.args())
                        {
                            arg->accept(*this);
                        }
                        depth -= 2;
                    }
                }

                inline void visit(ast::expr::Index &index)
                {
                    stream() << spaces() << "Index:" << std::endl;
                    if (index.expr())
                    {
                        depth++;
                        stream() << spaces() << "Expression:" << std::endl;
                        depth++;
                        index.expr()->accept(*this);
                        depth -= 2;
                    }
                    if (index.index())
                    {
                        depth++;
                        stream() << spaces() << "Index:" << std::endl;
                        depth++;
                        index.index()->accept(*this);
                        depth -= 2;
                    }
                }

                inline std::ostream &stream(void) const
                {
                    return m_stream;
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
                std::ostream &m_stream;
            };
        }
    }
}

#endif /* ECMA_AST_TOOLS_PRINT_VISITOR_H_ */
