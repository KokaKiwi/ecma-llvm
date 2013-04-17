#ifndef ECMA_AST_EXPR_ASSIGN_H_
#define ECMA_AST_EXPR_ASSIGN_H_

#include <string>
#include <memory>
#include <ostream>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Assign: public ast::Expression
            {
            public:
                enum class Type;

                inline Assign(Type type, ast::Expression *left, ast::Expression *expr): m_type(type), m_left(left), m_expr(expr) {}

                inline ast::Expression *left(void) const
                {
                    return m_left.get();
                }
                inline Assign &left(ast::Expression *left)
                {
                    m_left.reset(left);
                    return *this;
                }
                inline ast::Expression *takeLeft(void)
                {
                    return m_expr.release();
                }

                inline const Type type(void) const
                {
                    return m_type;
                }
                inline Assign &type(Type type)
                {
                    m_type = type;
                    return *this;
                }

                inline ast::Expression *expr(void) const
                {
                    return m_expr.get();
                }
                inline Assign &expr(ast::Expression *expr)
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
                std::unique_ptr<ast::Expression> m_left;
                Type m_type;
                std::unique_ptr<ast::Expression> m_expr;
            };

            enum class Assign::Type: int
            {
                Assign,
                PlusAssign,
                MinusAssign,
                MulAssign,
                DivAssign,
                ModAssign,
                RightShiftAssign,
                BinaryAndAssign,
                BinaryOrAssign,
                XorAssign
            };

            inline std::ostream& operator<<(std::ostream& os, const Assign::Type &type)
            {
                switch (type)
                {
                    case Assign::Type::Assign:
                        os << "Assign";
                        break;
                    case Assign::Type::PlusAssign:
                        os << "PlusAssign";
                        break;
                    case Assign::Type::MinusAssign:
                        os << "MinusAssign";
                        break;
                    case Assign::Type::MulAssign:
                        os << "MulAssign";
                        break;
                    case Assign::Type::DivAssign:
                        os << "DivAssign";
                        break;
                    case Assign::Type::ModAssign:
                        os << "ModAssign";
                        break;
                    case Assign::Type::RightShiftAssign:
                        os << "RightShiftAssign";
                        break;
                    case Assign::Type::BinaryAndAssign:
                        os << "BinaryAndAssign";
                        break;
                    case Assign::Type::BinaryOrAssign:
                        os << "BinaryOrAssign";
                        break;
                    case Assign::Type::XorAssign:
                        os << "XorAssign";
                        break;
                }

                return os;
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_ASSIGN_H_ */
