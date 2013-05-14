#ifndef ECMA_RUNTIME_TYPE_STRING_H_
#define ECMA_RUNTIME_TYPE_STRING_H_

#include <string>
#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class String: public Object
            {
            public:
                inline String(const std::string &value): m_value(value) {}

                virtual Object *operatorPlus(Object *other) const;

                virtual std::string toString(void) const;

                inline const std::string &value(void) const
                {
                    return m_value;
                }
                inline String &value(const std::string &value)
                {
                    m_value = value;
                    return *this;
                }

            private:
                std::string m_value;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_STRING_H_ */
