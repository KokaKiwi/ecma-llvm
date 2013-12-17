#ifndef ECMA_AST_STMT_DEBUG_H_
#define ECMA_AST_STMT_DEBUG_H_

#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Debug: public Statement
            {
                public:
                    inline Debug()
                        : Statement()
                    {
                    }
                    virtual inline ~Debug()
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

#endif /* ECMA_AST_STMT_DEBUG_H_ */
