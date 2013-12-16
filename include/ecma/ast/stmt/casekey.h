#ifndef ECMA_AST_STMT_CASEKEY_H_
#define ECMA_AST_STMT_CASEKEY_H_

#include "ecma/utils/element.h"
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class CaseKey: public utils::Element
            {
                public:
                    inline CaseKey()
                        : utils::Element()
                    {
                    }
                    inline ~CaseKey()
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
                    inline Expression *expr()
                    {
                        return m_expr.release();
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<Expression> m_expr;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_CASEKEY_H_ */
