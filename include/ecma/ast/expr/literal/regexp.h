#ifndef ECMA_AST_EXPR_LITERAL_REGEXP_H_
#define ECMA_AST_EXPR_LITERAL_REGEXP_H_

#include <string>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Regexp: public Expression
                {
                    public:
                        Regexp(const std::string &value);
                        virtual inline ~Regexp()
                        {
                        }

                        inline const std::string value() const
                        {
                            return m_value;
                        }
                        inline Regexp &value(std::string value)
                        {
                            m_value = value;
                            return *this;
                        }

                        inline const std::string attrs() const
                        {
                            return m_attrs;
                        }
                        inline Regexp &attrs(std::string attrs)
                        {
                            m_attrs = attrs;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::string m_value;
                        std::string m_attrs;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_REGEXP_H_ */
