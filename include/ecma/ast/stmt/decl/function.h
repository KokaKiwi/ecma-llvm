#ifndef ECMA_AST_STMT_DECL_FUNCTION_H_
#define ECMA_AST_STMT_DECL_FUNCTION_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace decl
            {
                class Function: public ast::Statement
                {
                public:
                    inline Function(const std::string &name, ast::expr::literal::Function *literal = nullptr): m_name(name), m_literal(literal) {}

                    inline const std::string &name(void) const
                    {
                        return m_name;
                    }
                    inline ecma::ast::stmt::decl::Function &name(const std::string &name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline ast::expr::literal::Function *literal(void) const
                    {
                        return m_literal.get();
                    }
                    inline ecma::ast::stmt::decl::Function &literal(ast::expr::literal::Function * literal)
                    {
                        m_literal.reset(literal);
                        return *this;
                    }
                    inline ast::expr::literal::Function *takeLiteral(void)
                    {
                        return m_literal.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::string m_name;
                    std::unique_ptr<ast::expr::literal::Function> m_literal;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_DECL_FUNCTION_H_ */
