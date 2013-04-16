#ifndef ECMA_AST_STMT_RETURN_H_
#define ECMA_AST_STMT_RETURN_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Return: public ast::Statement
            {
            public:
                inline Return(ast::Expression *expr = nullptr): m_expr(expr) {}

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::stmt::Return &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_RETURN_H_ */
