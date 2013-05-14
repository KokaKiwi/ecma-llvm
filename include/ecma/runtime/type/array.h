#ifndef ECMA_RUNTIME_TYPE_ARRAY_H_
#define ECMA_RUNTIME_TYPE_ARRAY_H_

#include <vector>
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
                Array(int size, Object **elems);

                virtual std::string toString(void) const;

                inline const std::vector<Object *> &elems(void) const
                {
                    return m_elems;
                }
                inline Array &elems(std::vector<Object *> &elems)
                {
                    m_elems = elems;
                    return *this;
                }

            private:
                std::vector<Object *> m_elems;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_ARRAY_H_ */
