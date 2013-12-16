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
                    inline ~Debug()
                    {
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
            };
        }
    }
}

#endif /* ECMA_AST_STMT_DEBUG_H_ */
