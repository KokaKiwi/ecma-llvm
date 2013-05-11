#ifndef ECMA_RUNTIME_TYPE_NULL_H_
#define ECMA_RUNTIME_TYPE_NULL_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Null: public Object
            {
            public:
                inline Null() {}
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_NULL_H_ */
