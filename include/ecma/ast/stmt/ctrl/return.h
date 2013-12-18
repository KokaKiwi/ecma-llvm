#ifndef ECMA_AST_STMT_CTRL_RETURN_H_
#define ECMA_AST_STMT_CTRL_RETURN_H_

#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Return: public Statement
                {
                    public:
                        inline Return()
                            : Statement()
                        {
                        }
                        virtual inline ~Return()
                        {
                        }

                        inline const Expression *expr() const
                        {
                            return m_expr.get();
                        }
                        inline Return &expr(Expression *expr)
                        {
                            m_expr.reset(expr);
                            return *this;
                        }
                        inline Expression *take_expr()
                        {
                            return m_expr.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Expression> m_expr;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_RETURN_H_ */
