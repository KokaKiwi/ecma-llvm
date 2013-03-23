#ifndef ECMA_AST_EXPR_ASSIGNMENT_H_
#define ECMA_AST_EXPR_ASSIGNMENT_H_

#include <string>
#include <memory>
#include "ecma/ast/expression.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Assignment: public ast::Expression
            {
            public:
                Assignment(const std::string &name, ast::Expression *value = nullptr): m_name(name), m_value(value) {}

                inline const std::string &name(void) const
                {
                    return m_name;
                }
                inline Assignment &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                inline ast::Expression *value(void) const
                {
                    return m_value.get();
                }
                inline Assignment &value(ast::Expression *value)
                {
                    m_value.reset(value);

                    return *this;
                }
                inline ast::Expression *takeValue(void)
                {
                    return m_value.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::string m_name;
                std::unique_ptr<ast::Expression> m_value;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_ASSIGNMENT_H_ */
