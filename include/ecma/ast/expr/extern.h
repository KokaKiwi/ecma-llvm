#ifndef ECMA_AST_EXPR_EXTERN_H_
#define ECMA_AST_EXPR_EXTERN_H_

#include <string>
#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Extern: public Expression
            {
            public:
                inline Extern(const std::string &name): m_name(name) {}

                inline const std::string &name(void) const
                {
                    return m_name;
                }
                inline Extern &name(std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::string m_name;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_EXTERN_H_ */
