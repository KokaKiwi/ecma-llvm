#ifndef ECMA_AST_EXPR_IDENTIFIER_H_
#define ECMA_AST_EXPR_IDENTIFIER_H_

#include <string>
#include "ecma/ast/expression.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Identifier: public Expression
            {
            public:
                inline Identifier(const std::string &name): m_name(name) {}

                inline const std::string &name(void) const
                {
                    return m_name;
                }
                inline Identifier &name(std::string &name)
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

#endif /* ECMA_AST_EXPR_IDENTIFIER_H_ */
