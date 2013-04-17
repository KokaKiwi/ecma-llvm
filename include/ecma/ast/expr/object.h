#ifndef ECMA_AST_EXPR_OBJECT_H_
#define ECMA_AST_EXPR_OBJECT_H_

#include <memory>
#include <vector>
#include <utility>
#include "ecma/ast/ast.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            class Object: public ast::Expression
            {
            public:
                class Property;

                inline Object(std::vector<Property *> *properties = nullptr): m_properties(properties) {}

                inline std::vector<Property *> *properties(void) const
                {
                    return m_properties.get();
                }
                inline ecma::ast::expr::Object &properties(std::vector<Property *> * properties)
                {
                    m_properties.reset(properties);
                    return *this;
                }
                inline std::vector<Property *> *takeProperties(void)
                {
                    return m_properties.release();
                }

                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }

            private:
                std::unique_ptr<std::vector<Property *> > m_properties;
            };

            class Object::Property
            {
            public:
                inline Property(lex::Lexeme *key, ast::Expression *value): m_key(key), m_value(value) {}

                inline lex::Lexeme *key(void) const
                {
                    return m_key.get();
                }
                inline ecma::ast::expr::Object::Property &key(lex::Lexeme *key)
                {
                    m_key.reset(key);
                    return *this;
                }
                inline lex::Lexeme *takeKey(void)
                {
                    return m_key.release();
                }

                inline ast::Expression *value(void) const
                {
                    return m_value.get();
                }
                inline ecma::ast::expr::Object::Property &value(ast::Expression *value)
                {
                    m_value.reset(value);
                    return *this;
                }
                inline ast::Expression *takeValue(void)
                {
                    return m_value.release();
                }

            private:
                std::unique_ptr<lex::Lexeme> m_key;
                std::unique_ptr<ast::Expression> m_value;
            };
        }
    }
}

#endif /* ECMA_AST_EXPR_OBJECT_H_ */
