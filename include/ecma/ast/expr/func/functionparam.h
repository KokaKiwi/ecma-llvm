#ifndef ECMA_AST_EXPR_FUNC_FUNCTIONPARAM_H_
#define ECMA_AST_EXPR_FUNC_FUNCTIONPARAM_H_

#include "ecma/utils/element.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace func
            {
                class FunctionParam: public utils::Element
                {
                    public:
                        inline FunctionParam(std::string name)
                            : utils::Element()
                            , m_name(name)
                        {
                        }
                        virtual inline ~FunctionParam()
                        {
                        }

                        inline const std::string name() const
                        {
                            return m_name;
                        }
                        inline FunctionParam &name(std::string name)
                        {
                            m_name = name;
                            return *this;
                        }

                        inline const std::string type() const
                        {
                            return m_type;
                        }
                        inline FunctionParam &type(std::string type)
                        {
                            m_type = type;
                            return *this;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::string m_name;
                        std::string m_type;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_FUNC_FUNCTIONPARAM_H_ */
