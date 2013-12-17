#ifndef ECMA_AST_EXPR_ARRAY_H_
#define ECMA_AST_EXPR_ARRAY_H_

#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Array: public Expression
            {
                public:
                    inline Array()
                        : Expression()
                    {
                    }
                    virtual inline ~Array()
                    {
                    }

                    inline const std::vector<std::unique_ptr<Expression>> &elements() const
                    {
                        return m_elements;
                    }
                    inline std::vector<std::unique_ptr<Expression>> &elements()
                    {
                        return m_elements;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<std::unique_ptr<Expression>> m_elements;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_ARRAY_H_ */
