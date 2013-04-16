#ifndef ECMA_AST_EXPR_LITERAL_FUNCTION_H_
#define ECMA_AST_EXPR_LITERAL_FUNCTION_H_

#include <memory>
#include <vector>
#include <string>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace literal
            {
                class Function: public ast::Expression
                {
                public:
                    inline Function(std::vector<std::string> *args, ast::stmt::Block *block): m_args(args), m_block(block) {}

                    inline std::vector<std::string> *args(void) const
                    {
                        return m_args.get();
                    }
                    inline ecma::ast::expr::literal::Function &args(std::vector<std::string> * args)
                    {
                        m_args.reset(args);
                        return *this;
                    }
                    inline std::vector<std::string> *takeArgs(void)
                    {
                        return m_args.release();
                    }

                    inline ast::stmt::Block *block(void) const
                    {
                        return m_block.get();
                    }
                    inline ecma::ast::expr::literal::Function &block(ast::stmt::Block * block)
                    {
                        m_block.reset(block);
                        return *this;
                    }
                    inline ast::stmt::Block *takeBlock(void)
                    {
                        return m_block.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<std::vector<std::string>> m_args;
                    std::unique_ptr<ast::stmt::Block> m_block;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_LITERAL_FUNCTION_H_ */
