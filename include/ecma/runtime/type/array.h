#ifndef ECMA_RUNTIME_TYPE_ARRAY_H_
#define ECMA_RUNTIME_TYPE_ARRAY_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Array: public Object
            {
            public:
                inline Array(int size, Object **elems): m_size(size), m_elems(elems) {}

                inline int size(void) const
                {
                    return m_size;
                }
                inline Array &size(int size)
                {
                    m_size = size;
                    return *this;
                }

                inline Object **elems(void) const
                {
                    return m_elems;
                }
                inline Array &elems(Object **elems)
                {
                    m_elems = elems;
                    return *this;
                }

            private:
                int m_size;
                Object **m_elems;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_ARRAY_H_ */
