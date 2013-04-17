#ifndef ECMA_AST_STMT_CTRL_TRY_H_
#define ECMA_AST_STMT_CTRL_TRY_H_

#include <memory>
#include <string>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Try: public ast::Statement
                {
                public:
                    class Catch;

                    inline Try(ast::stmt::Block *block, Catch *catchBranch = nullptr, ast::stmt::Block *finallyBranch = nullptr): m_block(block), m_catchBranch(catchBranch), m_finallyBranch(finallyBranch) {}

                    inline ast::stmt::Block *block(void) const
                    {
                        return m_block.get();
                    }
                    inline ecma::ast::stmt::ctrl::Try &block(ast::stmt::Block * block)
                    {
                        m_block.reset(block);
                        return *this;
                    }
                    inline ast::stmt::Block *takeBlock(void)
                    {
                        return m_block.release();
                    }

                    inline Catch *catchBranch(void) const
                    {
                        return m_catchBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::Try &catchBranch(Catch * catchBranch)
                    {
                        m_catchBranch.reset(catchBranch);
                        return *this;
                    }
                    inline Catch *takeCatchBranch(void)
                    {
                        return m_catchBranch.release();
                    }

                    inline ast::stmt::Block *finallyBranch(void) const
                    {
                        return m_finallyBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::Try &finallyBranch(ast::stmt::Block * finallyBranch)
                    {
                        m_finallyBranch.reset(finallyBranch);
                        return *this;
                    }
                    inline ast::stmt::Block *takeFinallyBranch(void)
                    {
                        return m_finallyBranch.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<ast::stmt::Block> m_block;
                    std::unique_ptr<Catch> m_catchBranch;
                    std::unique_ptr<ast::stmt::Block> m_finallyBranch;
                };

                class Try::Catch
                {
                public:
                    inline Catch(const std::string &name, ast::stmt::Block *block): m_name(name), m_block(block) {}

                    inline const std::string &name(void) const
                    {
                        return m_name;
                    }
                    inline Catch &name(std::string &name)
                    {
                        m_name = name;
                        return *this;
                    }

                    inline ast::stmt::Block *block(void) const
                    {
                        return m_block.get();
                    }
                    inline Catch &block(ast::stmt::Block * block)
                    {
                        m_block.reset(block);
                        return *this;
                    }
                    inline ast::stmt::Block *takeBlock(void)
                    {
                        return m_block.release();
                    }

                private:
                    std::string m_name;
                    std::unique_ptr<ast::stmt::Block> m_block;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_TRY_H_ */
