#ifndef ECMA_AST_EXPR_BINARY_H_
#define ECMA_AST_EXPR_BINARY_H_

#include <memory>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Binary: public ast::Expression
            {
            public:
                enum class Type;

                inline Binary(Type type, ast::Expression *left, ast::Expression *right): m_type(type), m_left(left), m_right(right) {}

                inline const Type type(void) const
                {
                    return m_type;
                }
                inline ecma::ast::expr::Binary &type(Type type)
                {
                    m_type = type;
                    return *this;
                }

                inline ast::Expression *left(void) const
                {
                    return m_left.get();
                }
                inline ecma::ast::expr::Binary &left(ast::Expression * left)
                {
                    m_left.reset(left);
                    return *this;
                }
                inline ast::Expression *takeLeft(void)
                {
                    return m_left.release();
                }

                inline ast::Expression *right(void) const
                {
                    return m_right.get();
                }
                inline ecma::ast::expr::Binary &right(ast::Expression * right)
                {
                    m_right.reset(right);
                    return *this;
                }
                inline ast::Expression *takeRight(void)
                {
                    return m_right.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                Type m_type;
                std::unique_ptr<ast::Expression> m_left;
                std::unique_ptr<ast::Expression> m_right;
            };

            enum class Binary::Type: int
            {
                LogicalOr,
                LogicalAnd,

                BitwiseOr,
                BitwiseXor,
                BitwiseAnd,

                Equal,
                NotEqual,
                Identity,
                NotIdentity,

                Lesser,
                LesserOrEqual,
                Greater,
                GreaterOrEqual,
                InstanceOf,
                In,

                LeftShift,
                RightShift,

                Plus,
                Minus,
                Mul,
                Div,
                Mod
            };

            inline std::ostream& operator<<(std::ostream& os, const Binary::Type &type)
            {
                switch (type)
                {
                    case Binary::Type::LogicalOr:
                        os << "LogicalOr";
                        break;
                    case Binary::Type::LogicalAnd:
                        os << "LogicalAnd";
                        break;
                    case Binary::Type::BitwiseOr:
                        os << "BitwiseOr";
                        break;
                    case Binary::Type::BitwiseXor:
                        os << "BitwiseXor";
                        break;
                    case Binary::Type::BitwiseAnd:
                        os << "BitwiseAnd";
                        break;
                    case Binary::Type::Equal:
                        os << "Equal";
                        break;
                    case Binary::Type::NotEqual:
                        os << "NotEqual";
                        break;
                    case Binary::Type::Identity:
                        os << "Identity";
                        break;
                    case Binary::Type::NotIdentity:
                        os << "NotIdentity";
                        break;
                    case Binary::Type::Lesser:
                        os << "Lesser";
                        break;
                    case Binary::Type::LesserOrEqual:
                        os << "LesserOrEqual";
                        break;
                    case Binary::Type::Greater:
                        os << "Greater";
                        break;
                    case Binary::Type::GreaterOrEqual:
                        os << "GreaterOrEqual";
                        break;
                    case Binary::Type::InstanceOf:
                        os << "InstanceOf";
                        break;
                    case Binary::Type::In:
                        os << "In";
                        break;
                    case Binary::Type::LeftShift:
                        os << "LeftShift";
                        break;
                    case Binary::Type::RightShift:
                        os << "RightShift";
                        break;
                    case Binary::Type::Plus:
                        os << "Plus";
                        break;
                    case Binary::Type::Minus:
                        os << "Minus";
                        break;
                    case Binary::Type::Mul:
                        os << "Mul";
                        break;
                    case Binary::Type::Div:
                        os << "Div";
                        break;
                    case Binary::Type::Mod:
                        os << "Mod";
                        break;
                }

                return os;
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_BINARY_H_ */
