#ifndef ECMA_AST_STMT_CTRL_SWITCH_H_
#define ECMA_AST_STMT_CTRL_SWITCH_H_

#include <memory>
#include <vector>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class Switch: public ast::Statement
                {
                public:
                    class Case;

                    inline Switch(ast::Expression *expr, std::vector<Case *> *caseblock): m_expr(expr), m_caseblock(caseblock) {}

                    inline ast::Expression *expr(void) const
                    {
                        return m_expr.get();
                    }
                    inline ecma::ast::stmt::ctrl::Switch &expr(ast::Expression * expr)
                    {
                        m_expr.reset(expr);
                        return *this;
                    }
                    inline ast::Expression *takeExpr(void)
                    {
                        return m_expr.release();
                    }

                    inline std::vector<Case *> *caseblock(void) const
                    {
                        return m_caseblock.get();
                    }
                    inline ecma::ast::stmt::ctrl::Switch &caseblock(std::vector<Case *> * caseblock)
                    {
                        m_caseblock.reset(caseblock);
                        return *this;
                    }
                    inline std::vector<Case *> *takeCaseblock(void)
                    {
                        return m_caseblock.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<ast::Expression> m_expr;
                    std::unique_ptr<std::vector<Case *> > m_caseblock;
                };

                class Switch::Case
                {
                public:
                    inline Case(ast::stmt::Block *block = nullptr, ast::Expression *key = nullptr): m_block(block), m_key(key) {}

                    inline ast::stmt::Block *block(void) const
                    {
                        return m_block.get();
                    }
                    inline Switch::Case &block(ast::stmt::Block * block)
                    {
                        m_block.reset(block);
                        return *this;
                    }
                    inline ast::stmt::Block *takeBlock(void)
                    {
                        return m_block.release();
                    }

                    inline ast::Expression *key(void) const
                    {
                        return m_key.get();
                    }
                    inline Switch::Case &key(ast::Expression * key)
                    {
                        m_key.reset(key);
                        return *this;
                    }
                    inline ast::Expression *takeKey(void)
                    {
                        return m_key.release();
                    }

                private:
                    std::unique_ptr<ast::stmt::Block> m_block;
                    std::unique_ptr<ast::Expression> m_key;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_SWITCH_H_ */
