#ifndef ECMA_AST_EXPR_UNARY_H_
#define ECMA_AST_EXPR_UNARY_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Unary: public ast::Expression
            {
            public:
                enum class Type;

                inline Unary(Type type, ast::Expression *expr): m_type(type), m_expr(expr) {}

                inline const Type type(void) const
                {
                    return m_type;
                }
                inline ecma::ast::expr::Unary &type(Type type)
                {
                    m_type = type;
                    return *this;
                }

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline ecma::ast::expr::Unary &expr(ast::Expression * expr)
                {
                    m_expr.reset(expr);
                    return *this;
                }
                inline ast::Expression *takeExpr(void)
                {
                    return m_expr.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                Type m_type;
                std::unique_ptr<ast::Expression> m_expr;
            };

            enum class Unary::Type: int
            {
                Not,
                Inv,
                PreIncrementation,
                PreDecrementation,
                TypeOf,

                PostIncrementation,
                PostDecrementation
            };

            inline std::ostream& operator<<(std::ostream& os, const Unary::Type &type)
            {
                switch(type)
                {
                    case Unary::Type::Not:
                        os << "Not";
                        break;
                    case Unary::Type::Inv:
                        os << "Inv";
                        break;
                    case Unary::Type::PreIncrementation:
                        os << "PreIncrementation";
                        break;
                    case Unary::Type::PreDecrementation:
                        os << "PreDecrementation";
                        break;
                    case Unary::Type::TypeOf:
                        os << "TypeOf";
                        break;
                    case Unary::Type::PostIncrementation:
                        os << "PostIncrementation";
                        break;
                    case Unary::Type::PostDecrementation:
                        os << "PostDecrementation";
                        break;
                }

                return os;
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_UNARY_H_ */
