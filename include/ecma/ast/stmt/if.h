#ifndef ECMA_AST_STMT_IF_H_
#define ECMA_AST_STMT_IF_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class If: public Statement
            {
                public:
                    inline If(Expression *cond_expr, Statement *then_stmt)
                        : Statement()
                        , m_cond_expr(cond_expr)
                        , m_then_stmt(then_stmt)
                    {}

                    inline const Expression *cond_expr() const
                    {
                        return m_cond_expr.get();
                    }
                    inline If &cond_expr(Expression *cond_expr)
                    {
                        m_cond_expr.reset(cond_expr);
                        return *this;
                    }
                    inline Expression *cond_expr()
                    {
                        return m_cond_expr.release();
                    }

                    inline const Statement *then_stmt() const
                    {
                        return m_then_stmt.get();
                    }
                    inline If &then_stmt(Statement *then_stmt)
                    {
                        m_then_stmt.reset(then_stmt);
                        return *this;
                    }
                    inline Statement *then_stmt()
                    {
                        return m_then_stmt.release();
                    }

                    inline const Statement *else_stmt() const
                    {
                        return m_else_stmt.get();
                    }
                    inline If &else_stmt(Statement *else_stmt)
                    {
                        m_else_stmt.reset(else_stmt);
                        return *this;
                    }
                    inline Statement *else_stmt()
                    {
                        return m_else_stmt.release();
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_cond_expr;
                    std::unique_ptr<Statement> m_then_stmt;
                    std::unique_ptr<Statement> m_else_stmt;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_IF_H_ */
