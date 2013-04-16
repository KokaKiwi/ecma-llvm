#ifndef ECMA_AST_STMT_CTRL_IF_H_
#define ECMA_AST_STMT_CTRL_IF_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class If: public ast::Statement
                {
                public:
                    inline If(ast::Expression *expr, ast::Statement *thenBranch, ast::Statement *elseBranch = nullptr): m_expr(expr), m_thenBranch(thenBranch), m_elseBranch(elseBranch) {}

                    inline ast::Expression *expr(void) const
                    {
                        return m_expr.get();
                    }
                    inline ecma::ast::stmt::ctrl::If &expr(ast::Expression * expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline ast::Expression *takeExpr(void)
                    {
                        return m_expr.release();
                    }

                    inline ast::Statement *thenBranch(void) const
                    {
                        return m_thenBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::If &thenBranch(ast::Statement * thenBranch)
                    {
                        m_thenBranch.reset(thenBranch);
                        return *this;
                    }
                    inline ast::Statement *takeThenbranch(void)
                    {
                        return m_thenBranch.release();
                    }

                    inline ast::Statement *elseBranch(void) const
                    {
                        return m_elseBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::If &elseBranch(ast::Statement * elseBranch)
                    {
                        m_elseBranch.reset(elseBranch);
                        return *this;
                    }
                    inline ast::Statement *takeElsebranch(void)
                    {
                        return m_elseBranch.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<ast::Expression> m_expr;
                    std::unique_ptr<ast::Statement> m_thenBranch;
                    std::unique_ptr<ast::Statement> m_elseBranch;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_IF_H_ */
