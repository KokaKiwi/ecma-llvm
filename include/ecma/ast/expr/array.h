#ifndef ECMA_AST_EXPR_ARRAY_H_
#define ECMA_AST_EXPR_ARRAY_H_

#include <memory>
#include <vector>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Array: public ast::Expression
            {
            public:
                inline Array(std::vector<ast::Expression *> *values = nullptr): m_values(values) {}

                inline std::vector<ast::Expression *> *values(void) const
                {
                    return m_values.get();
                }
                inline ecma::ast::expr::Array &values(std::vector<ast::Expression *> * values)
                {
                    m_values.reset(values);
                    return *this;
                }
                inline std::vector<ast::Expression *> *takeValues(void)
                {
                    return m_values.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<std::vector<ast::Expression *> > m_values;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_ARRAY_H_ */
