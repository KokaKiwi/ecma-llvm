#ifndef ECMA_RUNTIME_TYPE_UNDEFINED_H_
#define ECMA_RUNTIME_TYPE_UNDEFINED_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Undefined: public Object
            {
            public:
                inline Undefined() {}
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_UNDEFINED_H_ */
