#ifndef ECMA_AST_STMT_BLOCK_H_
#define ECMA_AST_STMT_BLOCK_H_

#include <vector>
#include "ecma/ast/statement.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Block: public ast::Statement
            {
            public:
                inline Block(void) {}

                inline ~Block(void)
                {
                    for (ast::Statement *stmt : m_statements)
                    {
                        delete stmt;
                    }
                }

                inline std::vector<ast::Statement *> &statements(void)
                {
                    return m_statements;
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::vector<ast::Statement *> m_statements;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_BLOCK_H_ */
