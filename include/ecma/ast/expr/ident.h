#ifndef ECMA_AST_EXPR_IDENT_H_
#define ECMA_AST_EXPR_IDENT_H_

#include <string>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Ident: public Expression
            {
                public:
                    inline Ident(std::string name)
                        : Expression()
                        , m_name(name)
                    {
                    }
                    inline ~Ident()
                    {
                    }

                    inline const std::string name() const
                    {
                        return m_name;
                    }
                    inline Ident &name(std::string name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_name;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_IDENT_H_ */
