#ifndef ECMA_AST_TOOLS_PRINT_VISITOR_H_
#define ECMA_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/ast/stmt/decl/variables.h"

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
                            depth--;
                        }
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
