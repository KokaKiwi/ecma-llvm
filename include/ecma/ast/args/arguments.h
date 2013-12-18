#ifndef ECMA_AST_ARGS_ARGUMENTS_H_
#define ECMA_AST_ARGS_ARGUMENTS_H_

#include <vector>
#include <memory>
#include "ecma/utils/element.h"
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace args
        {
            class Arguments: public utils::Element
            {
                public:
                    inline Arguments()
                        : utils::Element()
                    {
                    }
                    virtual inline ~Arguments()
                    {
                    }

                    inline const std::vector<std::unique_ptr<Expression>> &elements() const
                    {
                        return m_elements;
                    }
                    inline std::vector<std::unique_ptr<Expression>> &elements()
                    {
                        return m_elements;
                    }

                    virtual inline void accept(tools::Visitor &visitor) const
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::vector<std::unique_ptr<Expression>> m_elements;
            };
        }
    }
}

#endif /* ECMA_AST_ARGS_ARGUMENTS_H_ */
