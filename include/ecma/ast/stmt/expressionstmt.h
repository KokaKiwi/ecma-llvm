#ifndef ECMA_AST_STMT_EXPRESSIONSTMT_H_
#define ECMA_AST_STMT_EXPRESSIONSTMT_H_

#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class ExpressionStmt: public Statement
            {
                public:
                    inline ExpressionStmt(Expression *expr)
                        : Statement()
                        , m_expr(expr)
                    {
                    }
                    virtual inline ~ExpressionStmt()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline ExpressionStmt &expr(Expression *expr)
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

#endif /* ECMA_AST_STMT_EXPRESSIONSTMT_H_ */
