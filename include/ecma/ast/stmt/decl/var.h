#ifndef ECMA_AST_STMT_DECL_VAR_H_
#define ECMA_AST_STMT_DECL_VAR_H_

#include "ecma/utils/element.h"
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
                class Var: public utils::Element
                {
                    public:
                        inline Var(std::string name)
                            : utils::Element()
                            , m_name(name)
                        {}

                        inline const std::string name() const
                        {
                            return m_name;
                        }
                        inline Var &name(std::string name)
                        {
                            m_name = name;
                            return *this;
                        }

                        inline const Expression *init() const
                        {
                            return m_init.get();
                        }
                        inline Var &init(Expression *init)
                        {
                            m_init.reset(init);
                            return *this;
                        }
                        inline Expression *init()
                        {
                            return m_init.release();
                        }

                        inline void accept(tools::Visitor &visitor)
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::string m_name;
                        std::unique_ptr<Expression> m_init;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_DECL_VAR_H_ */
