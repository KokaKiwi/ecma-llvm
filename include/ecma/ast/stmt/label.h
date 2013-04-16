#ifndef ECMA_AST_STMT_LABEL_H_
#define ECMA_AST_STMT_LABEL_H_

#include <string>
#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Label: public ast::Statement
            {
            public:
                inline Label(const std::string &name, ast::Statement *stmt): m_name(name), m_stmt(stmt) {}

                inline const std::string name(void) const
                {
                    return m_name;
                }
                inline ecma::ast::stmt::Label &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                inline ast::Statement *stmt(void) const
                {
                    return m_stmt.get();
                }
                inline ecma::ast::stmt::Label &stmt(ast::Statement * stmt)
                {
                    m_stmt.reset(stmt);
                    return *this;
                }
                inline ast::Statement *takeStmt(void)
                {
                    return m_stmt.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::string m_name;
                std::unique_ptr<ast::Statement> m_stmt;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_LABEL_H_ */
