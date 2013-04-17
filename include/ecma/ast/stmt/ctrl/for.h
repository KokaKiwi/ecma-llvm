#ifndef ECMA_AST_STMT_CTRL_FOR_H_
#define ECMA_AST_STMT_CTRL_FOR_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace stmt
        {
            namespace ctrl
            {
                class For: public ast::Statement
                {
                public:
                    inline For(ast::Node *initializer, ast::Expression *condBranch, ast::Expression *loopBranch, ast::Statement *thenBranch): m_initializer(initializer), m_condBranch(condBranch), m_loopBranch(loopBranch), m_thenBranch(thenBranch) {}

                    inline ast::Node *initializer(void) const
                    {
                        return m_initializer.get();
                    }
                    inline ecma::ast::stmt::ctrl::For &initializer(ast::Node * initializer)
                    {
                        m_initializer.reset(initializer);
                        return *this;
                    }
                    inline ast::Node *takeInitializer(void)
                    {
                        return m_initializer.release();
                    }

                    inline ast::Expression *condBranch(void) const
                    {
                        return m_condBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::For &condBranch(ast::Expression * condBranch)
                    {
                        m_condBranch.reset(condBranch);
                        return *this;
                    }
                    inline ast::Expression *takeCondbranch(void)
                    {
                        return m_condBranch.release();
                    }

                    inline ast::Expression *loopBranch(void) const
                    {
                        return m_loopBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::For &loopBranch(ast::Expression * loopBranch)
                    {
                        m_loopBranch.reset(loopBranch);
                        return *this;
                    }
                    inline ast::Expression *takeLoopbranch(void)
                    {
                        return m_loopBranch.release();
                    }

                    inline ast::Statement *thenBranch(void) const
                    {
                        return m_thenBranch.get();
                    }
                    inline ecma::ast::stmt::ctrl::For &thenBranch(ast::Statement * thenBranch)
                    {
                        m_thenBranch.reset(thenBranch);
                        return *this;
                    }
                    inline ast::Statement *takeThenbranch(void)
                    {
                        return m_thenBranch.release();
                    }

                    void accept(ast::tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<ast::Node> m_initializer;
                    std::unique_ptr<ast::Expression> m_condBranch;
                    std::unique_ptr<ast::Expression> m_loopBranch;
                    std::unique_ptr<ast::Statement> m_thenBranch;
                };
            }
        }
    }
}

#endif /* ECMA_AST_STMT_CTRL_FOR_H_ */
