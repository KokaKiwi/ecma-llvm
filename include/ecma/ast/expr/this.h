#ifndef ECMA_AST_EXPR_THIS_H_
#define ECMA_AST_EXPR_THIS_H_

#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class This: public Expression
            {
                public:
                    inline This()
                        : Expression()
                    {}

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_THIS_H_ */
