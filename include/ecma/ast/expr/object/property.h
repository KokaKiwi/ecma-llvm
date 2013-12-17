#ifndef ECMA_AST_EXPR_OBJECT_PROPERTY_H_
#define ECMA_AST_EXPR_OBJECT_PROPERTY_H_

#include "ecma/utils/element.h"
#include <memory>
#include "ecma/ast/tools/visitor.h"

namespace ecma
{
    namespace ast
    {
        namespace expr
        {
            namespace object
            {
                class Property: public utils::Element
                {
                    public:
                        inline Property()
                            : utils::Element()
                        {
                        }
                        virtual inline ~Property()
                        {
                        }

                        inline const Expression *key() const
                        {
                            return m_key.get();
                        }
                        inline Property &key(Expression *key)
                        {
                            m_key.reset(key);
                            return *this;
                        }
                        inline Expression *take_key()
                        {
                            return m_key.release();
                        }

                        inline const Expression *value() const
                        {
                            return m_value.get();
                        }
                        inline Property &value(Expression *value)
                        {
                            m_value.reset(value);
                            return *this;
                        }
                        inline Expression *take_value()
                        {
                            return m_value.release();
                        }

                        virtual inline void accept(tools::Visitor &visitor) const
                        {
                            visitor.visit(*this);
                        }

                    private:
                        std::unique_ptr<Expression> m_key;
                        std::unique_ptr<Expression> m_value;
                };
            }
        }
    }
}

#endif /* ECMA_AST_EXPR_OBJECT_PROPERTY_H_ */
