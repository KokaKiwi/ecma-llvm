#ifndef ECMA_AST_STMT_DECL_FUNCTION_H_
#define ECMA_AST_STMT_DECL_FUNCTION_H_

#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace decl
            {
                class Function: public Statement
                {
                    public:
                        inline Function(expr::Function *func)
                            : Statement()
                            , m_func(func)
                        {
                        }
                        virtual inline ~Function()
                        {
                        }

                        inline const expr::Function *func() const
                        {
                            return m_func.get();
                        }
                        inline Function &func(expr::Function *func)
                        {
                            m_func.reset(func);
                            return *this;
                        }
                        inline expr::Function *take_func()
                        {
                            return m_func.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<expr::Function> m_func;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_DECL_FUNCTION_H_ */
