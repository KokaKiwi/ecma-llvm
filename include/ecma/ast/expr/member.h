#ifndef ECMA_AST_EXPR_MEMBER_H_
#define ECMA_AST_EXPR_MEMBER_H_

#include <memory>
#include <string>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Member: public ast::Expression
            {
            public:
                inline Member(ast::Expression *expr, const std::string &name): m_expr(expr), m_name(name) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::expr::Member &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                inline const std::string name(void) const
                {
                    return m_name;
                }
                inline ecma::ast::expr::Member &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
                std::string m_name;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_MEMBER_H_ */
