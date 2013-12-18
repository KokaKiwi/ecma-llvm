#ifndef ECMA_AST_MODULE_H_
#define ECMA_AST_MODULE_H_

#include <vector>
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        class Module
        {
            public:
                inline Module()
                {
                }
                virtual inline ~Module()
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

                virtual inline void accept(tools::Visitor &visitor) const
                {
                    visitor.visit(*this);
                }

            private:
                std::vector<std::unique_ptr<Statement>> m_statements;
        };
    }
}

#endif /* ECMA_AST_MODULE_H_ */
