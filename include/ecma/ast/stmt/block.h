#ifndef ECMA_AST_STMT_BLOCK_H_
#define ECMA_AST_STMT_BLOCK_H_

#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Block: public Statement
            {
                public:
                    inline Block()
                        : Statement()
                    {
                    }
                    virtual inline ~Block()
                    {
                    }

                    inline const std::vector<std::unique_ptr<Statement>> &statements() const
                    {
                        return m_statements;
                    }
                    inline std::vector<std::unique_ptr<Statement>> &statements()
                    {
                        return m_statements;
                    }

                    virtual inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<std::unique_ptr<Statement>> m_statements;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_BLOCK_H_ */
