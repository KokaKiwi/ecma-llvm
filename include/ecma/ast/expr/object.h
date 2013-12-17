#ifndef ECMA_AST_EXPR_OBJECT_H_
#define ECMA_AST_EXPR_OBJECT_H_

#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Object: public Expression
            {
                public:
                    inline Object()
                        : Expression()
                    {
                    }
                    virtual inline ~Object()
                    {
                    }

                    inline const std::vector<std::unique_ptr<expr::object::Property>> &properties() const
                    {
                        return m_properties;
                    }
                    inline std::vector<std::unique_ptr<expr::object::Property>> &properties()
                    {
                        return m_properties;
                    }

                    virtual inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<std::unique_ptr<expr::object::Property>> m_properties;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_OBJECT_H_ */
