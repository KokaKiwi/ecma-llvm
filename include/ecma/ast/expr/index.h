#ifndef ECMA_AST_EXPR_INDEX_H_
#define ECMA_AST_EXPR_INDEX_H_

#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Index: public Expression
            {
                public:
                    inline Index()
                        : Expression()
                    {
                    }
                    virtual inline ~Index()
                    {
                    }

                    inline const Expression *expr() const
                    {
                        return m_expr.get();
                    }
                    inline Index &expr(Expression *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline Expression *take_expr()
                    {
                        return m_expr.release();
                    }

                    inline const Expression *index() const
                    {
                        return m_index.get();
                    }
                    inline Index &index(Expression *index)
                    {
                        m_index.reset(index);
                        return *this;
                    }
                    inline Expression *take_index()
                    {
                        return m_index.release();
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
                    std::unique_ptr<Expression> m_index;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_INDEX_H_ */
