#ifndef ECMA_RUNTIME_TYPE_BOOLEAN_H_
#define ECMA_RUNTIME_TYPE_BOOLEAN_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Boolean: public Object
            {
            public:
                inline Boolean(bool value): m_value(value) {}

                inline bool value(void) const
                {
                    return m_value;
                }
                inline Boolean &value(bool value)
                {
                    m_value = value;
                    return *this;
                }

            private:
                bool m_value;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_BOOLEAN_H_ */
