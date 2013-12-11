#ifndef ECMA_AST_STMT_IFSTATEMENT_H_
#define ECMA_AST_STMT_IFSTATEMENT_H_

#include <vector>
#include <memory>

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            class IfStatement: public ast::Statement
            {
                public:
                    inline IfStatement()
                    {}

                    inline const std::vector<std::unique_ptr<ast::Expression>> *expr() const
                    {
                        return m_expr.get();
                    }
                    inline IfStatement &expr(std::vector<std::unique_ptr<ast::Expression>> *expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline std::vector<std::unique_ptr<ast::Expression>> *expr()
                    {
                        return m_expr.release();
                    }

                private:
                    std::unique_ptr<std::vector<std::unique_ptr<ast::Expression>>> m_expr;
            };
        }
    }
}

#endif /* ECMA_AST_STMT_IFSTATEMENT_H_ */
