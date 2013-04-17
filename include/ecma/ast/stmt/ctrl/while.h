#ifndef ECMA_AST_STMT_CTRL_WHILE_H_
#define ECMA_AST_STMT_CTRL_WHILE_H_

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
                class While: public ast::Statement
                {
                public:
                    inline While(bool doFirst, ast::Expression *expr, ast::Statement *thenBranch): m_doFirst(doFirst), m_expr(expr), m_thenBranch(thenBranch) {}

                    inline const bool doFirst(void) const
                    {
                        return m_doFirst;
                    }
                    inline ecma::ast::stmt::ctrl::While &doFirst(bool doFirst)
                    {
                        m_doFirst = doFirst;
                        return *this;
                    }

                    inline ast::Expression *expr(void) const
                    {
                        return m_expr.get();
                    }
                    inline ecma::ast::stmt::ctrl::While &expr(ast::Expression * expr)
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
                    inline ecma::ast::stmt::ctrl::While &thenBranch(ast::Statement * thenBranch)
                    {
                        m_thenBranch.reset(thenBranch);
                        return *this;
                    }
                    inline ast::Statement *takeThenbranch(void)
                    {
                        return m_thenBranch.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    bool m_doFirst;
                    std::unique_ptr<ast::Expression> m_expr;
                    std::unique_ptr<ast::Statement> m_thenBranch;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_WHILE_H_ */
