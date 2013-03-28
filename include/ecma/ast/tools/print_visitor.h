#ifndef ECMA_AST_TOOLS_PRINT_VISITOR_H_
#define ECMA_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include "ecma/ast/tools/visitor.h"
#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"

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
