#ifndef ECMA_AST_EXPR_LITERAL_NUMBER_H_
#define ECMA_AST_EXPR_LITERAL_NUMBER_H_

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
                class Number: public Expression
                {
                    public:
                        Number(const std::string &value);
                        virtual inline ~Number()
                        {
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_NUMBER_H_ */
