#ifndef ECMA_AST_STMT_CTRL_CASEBLOCK_H_
#define ECMA_AST_STMT_CTRL_CASEBLOCK_H_

#include "ecma/utils/element.h"
#include <memory>
#include <vector>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class CaseBlock: public utils::Element
                {
                    public:
                        inline CaseBlock()
                            : utils::Element()
                        {
                        }
                        virtual inline ~CaseBlock()
                        {
                        }

                        inline const std::vector<std::unique_ptr<stmt::ctrl::Case>> &cases() const
                        {
                            return m_cases;
                        }
                        inline std::vector<std::unique_ptr<stmt::ctrl::Case>> &cases()
                        {
                            return m_cases;
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::vector<std::unique_ptr<stmt::ctrl::Case>> m_cases;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_CASEBLOCK_H_ */
