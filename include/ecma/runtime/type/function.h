#ifndef ECMA_RUNTIME_TYPE_FUNCTION_H_
#define ECMA_RUNTIME_TYPE_FUNCTION_H_

#include "ecma/runtime/object.h"

namespace ecma
{
    namespace runtime
    {
        namespace type
        {
            class Function: public Object
            {
            public:
                using Signature = Object *(int argc, Object **argv);

                inline Function(Signature *ptr): m_ptr(ptr) {}

                inline Signature *ptr(void) const
                {
                    return m_ptr;
                }
                inline Function &ptr(Signature *ptr)
                {
                    m_ptr = ptr;
                    return *this;
                }

            private:
                Signature *m_ptr;
            };
        }
    }
}

#endif /* ECMA_RUNTIME_TYPE_FUNCTION_H_ */
