#ifndef ECMA_AST_EXPR_CALL_H_
#define ECMA_AST_EXPR_CALL_H_

#include <memory>
#include <vector>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Call: public ast::Expression
            {
            public:
                inline Call(ast::Expression *expr, std::vector<ast::Expression *> *args): m_expr(expr), m_args(args) {}

                inline ~Call()
                {
                    if (args())
                    {
                        for (ast::Expression *arg : *m_args)
                        {
                            delete arg;
                        }
                    }
                }

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::expr::Call &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                inline std::vector<ast::Expression *> *args(void) const
                {
                    return m_args.get();
                }
                inline ecma::ast::expr::Call &args(std::vector<ast::Expression *> * args)
                {
                    m_args.reset(args);
                    return *this;
                }
                inline std::vector<ast::Expression *> *takeArgs(void)
                {
                    return m_args.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<ast::Expression> m_expr;
                std::unique_ptr<std::vector<ast::Expression *> > m_args;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_CALL_H_ */
