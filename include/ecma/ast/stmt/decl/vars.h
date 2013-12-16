#ifndef ECMA_AST_STMT_DECL_VARS_H_
#define ECMA_AST_STMT_DECL_VARS_H_

#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace decl
            {
                class Vars: public Statement
                {
                    public:
                        inline Vars()
                            : Statement()
                        {
                        }
                        inline ~Vars()
                        {
                        }

                        inline const std::vector<std::unique_ptr<stmt::decl::Var>> &decls() const
                        {
                            return m_decls;
                        }
                        inline std::vector<std::unique_ptr<stmt::decl::Var>> &decls()
                        {
                            return m_decls;
                        }

                        inline void accept(tools::Visitor &visitor)
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::vector<std::unique_ptr<stmt::decl::Var>> m_decls;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_DECL_VARS_H_ */
