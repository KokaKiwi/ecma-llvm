#ifndef ECMA_AST_EXPR_EXPRESSIONS_H_
#define ECMA_AST_EXPR_EXPRESSIONS_H_

#include <vector>
#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Expressions: public Expression
            {
                public:
                    inline Expressions()
                        : Expression()
                    {
                    }
                    virtual inline ~Expressions()
                    {
                    }

                    inline const std::vector<std::unique_ptr<Expression>> &items() const
                    {
                        return m_items;
                    }
                    inline std::vector<std::unique_ptr<Expression>> &items()
                    {
                        return m_items;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<std::unique_ptr<Expression>> m_items;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_EXPRESSIONS_H_ */
