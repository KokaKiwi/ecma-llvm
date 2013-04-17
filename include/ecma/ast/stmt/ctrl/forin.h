#ifndef ECMA_AST_STMT_CTRL_FORIN_H_
#define ECMA_AST_STMT_CTRL_FORIN_H_

#include <memory>
#include <string>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class ForIn: public ast::Statement
                {
                public:
                    inline ForIn(bool decl, const std::string &name, ast::Expression *expr, ast::Statement *thenBranch): m_decl(decl), m_name(name), m_expr(expr), m_thenBranch(thenBranch) {}

                    inline const bool decl(void) const
                    {
                        return m_decl;
                    }
                    inline ecma::ast::stmt::ctrl::ForIn &decl(bool decl)
                    {
                        m_decl = decl;
                        return *this;
                    }

                    inline const std::string &name(void) const
                    {
                        return m_name;
                    }
                    inline ecma::ast::stmt::ctrl::ForIn &name(const std::string &name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline ast::Expression *expr(void) const
                    {
                        return m_expr.get();
                    }
                    inline ecma::ast::stmt::ctrl::ForIn &expr(ast::Expression * expr)
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
                    inline ecma::ast::stmt::ctrl::ForIn &thenBranch(ast::Statement * thenBranch)
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
                    bool m_decl;
                    std::string m_name;
                    std::unique_ptr<ast::Expression> m_expr;
                    std::unique_ptr<ast::Statement> m_thenBranch;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_FORIN_H_ */
