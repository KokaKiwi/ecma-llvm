#ifndef ECMA_RUNTIME_TYPE_INTEGER_H_
#define ECMA_RUNTIME_TYPE_INTEGER_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Integer: public Object
            {
            public:
                inline Integer(int value): m_value(value) {}

                inline int value(void) const
                {
                    return m_value;
                }
                inline Integer &value(int value)
                {
                    m_value = value;
                    return *this;
                }

                virtual std::string toString(void) const;

            private:
                int m_value;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_INTEGER_H_ */
