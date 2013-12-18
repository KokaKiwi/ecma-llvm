#ifndef ECMA_AST_STMT_CTRL_SWITCH_H_
#define ECMA_AST_STMT_CTRL_SWITCH_H_

#include <vector>
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
                class Switch: public Statement
                {
                    public:
                        inline Switch(Expression *expr)
                            : Statement()
                            , m_expr(expr)
                        {
                        }
                        virtual inline ~Switch()
                        {
                        }

                        inline const Expression *expr() const
                        {
                            return m_expr.get();
                        }
                        inline Switch &expr(Expression *expr)
                        {
                            m_expr.reset(expr);
                            return *this;
                        }
                        inline Expression *take_expr()
                        {
                            return m_expr.release();
                        }

                        inline const std::vector<std::unique_ptr<stmt::ctrl::Case>> &cases() const
                        {
                            return m_cases;
                        }
                        inline std::vector<std::unique_ptr<stmt::ctrl::Case>> &cases()
                        {
                            return m_cases;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Expression> m_expr;
                        std::vector<std::unique_ptr<stmt::ctrl::Case>> m_cases;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_SWITCH_H_ */
