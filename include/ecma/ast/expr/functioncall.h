#ifndef ECMA_AST_EXPR_FUNCTIONCALL_H_
#define ECMA_AST_EXPR_FUNCTIONCALL_H_

#include <vector>
#include "ecma/ast/tools/visitor.h"
#include <memory>

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class FunctionCall: public ast::Expression
            {
                public:
                    inline FunctionCall()
                    {}

                    inline const ast::Expression *callee() const
                    {
                        return m_callee.get();
                    }
                    inline FunctionCall &callee(ast::Expression *callee)
                    {
                        m_callee.reset(callee);
                        return *this;
                    }
                    inline ast::Expression *callee()
                    {
                        return m_callee.release();
                    }

                    inline const std::vector<std::unique_ptr<ast::Expression>> *args() const
                    {
                        return m_args.get();
                    }
                    inline FunctionCall &args(std::vector<std::unique_ptr<ast::Expression>> *args)
                    {
                        m_args.reset(args);
                        return *this;
                    }
                    inline std::vector<std::unique_ptr<ast::Expression>> *args()
                    {
                        return m_args.release();
                    }

                    inline const int nargs() const
                    {
                        return m_nargs;
                    }
                    inline FunctionCall &nargs(int nargs)
                    {
                        m_nargs = nargs;
                        return *this;
                    }

                    inline void accept(tools::Visitor &visitor)
                    {
                        visitor.visit(*this);
                    }

                private:
                    std::unique_ptr<ast::Expression> m_callee;
                    std::unique_ptr<std::vector<std::unique_ptr<ast::Expression>>> m_args;
                    int m_nargs;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_FUNCTIONCALL_H_ */
