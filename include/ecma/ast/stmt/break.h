#ifndef ECMA_AST_STMT_BREAK_H_
#define ECMA_AST_STMT_BREAK_H_

#include <string>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class Break: public ast::Statement
            {
            public:
                inline Break(const std::string &name): m_name(name) {}

                inline const std::string name(void) const
                {
                    return m_name;
                }
                inline ecma::ast::stmt::Break &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::string m_name;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_BREAK_H_ */
