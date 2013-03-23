#ifndef ECMA_AST_STMT_DECL_FUNCTION_H_
#define ECMA_AST_STMT_DECL_FUNCTION_H_

#include <string>
#include <vector>
#include <memory>
#include "ecma/ast/statement.h"
#include "ecma/ast/stmt/block.h"
#include "ecma/ast/tools/visitor.h"

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
                    inline Function(const std::string &name, std::vector<std::string> *args, ast::stmt::Block *block): m_name(name), m_args(args), m_block(block) {}

                    inline const std::string &name(void) const
                    {
                        return m_name;
                    }
                    inline Function &name(const std::string &name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline std::vector<std::string> *args(void) const
                    {
                        return m_args.get();
                    }
                    inline Function &args(std::vector<std::string> *args)
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
                    inline Function &block(ast::stmt::Block *block)
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
                    std::string m_name;
                    std::unique_ptr<std::vector<std::string> > m_args;
                    std::unique_ptr<ast::stmt::Block> m_block;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_DECL_FUNCTION_H_ */
