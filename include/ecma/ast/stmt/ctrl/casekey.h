#ifndef ECMA_AST_STMT_CTRL_CASEKEY_H_
#define ECMA_AST_STMT_CTRL_CASEKEY_H_

#include "ecma/utils/element.h"
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class CaseKey: public utils::Element
                {
                    public:
                        inline CaseKey()
                            : utils::Element()
                        {
                        }
                        virtual inline ~CaseKey()
                        {
                        }

                        inline const Expression *expr() const
                        {
                            return m_expr.get();
                        }
                        inline CaseKey &expr(Expression *expr)
                        {
                            m_expr.reset(expr);
                            return *this;
                        }
                        inline Expression *take_expr()
                        {
                            return m_expr.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Expression> m_expr;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_CASEKEY_H_ */
