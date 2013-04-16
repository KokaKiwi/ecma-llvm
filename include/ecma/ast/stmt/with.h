#ifndef ECMA_AST_STMT_WITH_H_
#define ECMA_AST_STMT_WITH_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class With: public ast::Statement
            {
            public:
                inline With(ast::Expression *expr, ast::Statement *stmt): m_expr(expr), m_stmt(stmt) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::stmt::With &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                inline ast::Statement *stmt(void) const
                {
                    return m_stmt.get();
                }
                inline ecma::ast::stmt::With &stmt(ast::Statement * stmt)
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
                std::unique_ptr<ast::Expression> m_expr;
                std::unique_ptr<ast::Statement> m_stmt;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_WITH_H_ */
