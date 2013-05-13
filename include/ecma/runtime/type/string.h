#ifndef ECMA_RUNTIME_TYPE_STRING_H_
#define ECMA_RUNTIME_TYPE_STRING_H_

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
                inline String(char *value): m_value(value) {}

                inline const char *value(void) const
                {
                    return m_value;
                }
                inline String &value(char *value)
                {
                    m_value = value;
                    return *this;
                }

                virtual std::string toString(void) const;

            private:
                char *m_value;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_STRING_H_ */
