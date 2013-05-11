#ifndef ECMA_RUNTIME_CAPI_H_
#define ECMA_RUNTIME_CAPI_H_

#include "ecma/runtime/object.h"
#include "ecma/runtime/type/integer.h"
#include "ecma/runtime/type/string.h"
#include "ecma/runtime/type/boolean.h"
#include "ecma/runtime/type/null.h"
#include "ecma/runtime/type/function.h"
#include "ecma/runtime/type/undefined.h"

extern "C"
{
    #define ECMA_FUNCTION(NAME, RETURN, ...) RETURN NAME (__VA_ARGS__);
    #define ECMA_TYPE(TYPENAME, ...) ecma::runtime::type::TYPENAME *Ecma_##TYPENAME##_create(__VA_ARGS__);

    #include "ecma/runtime/capi.def.h"

    #undef ECMA_TYPE
    #undef ECMA_FUNCTION
}

#endif /* ECMA_RUNTIME_CAPI_H_ */
