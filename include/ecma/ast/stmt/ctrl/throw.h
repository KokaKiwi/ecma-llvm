#ifndef ECMA_AST_STMT_CTRL_THROW_H_
#define ECMA_AST_STMT_CTRL_THROW_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Throw: public Statement
                {
                    public:
                        inline Throw(Expression *expr)
                            : Statement()
                            , m_expr(expr)
                        {
                        }
                        virtual inline ~Throw()
                        {
                        }

                        inline const Expression *expr() const
                        {
                            return m_expr.get();
                        }
                        inline Throw &expr(Expression *expr)
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

#endif /* ECMA_AST_STMT_CTRL_THROW_H_ */
