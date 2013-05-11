#ifndef ECMA_RUNTIME_CAPI_CALL_H_
#define ECMA_RUNTIME_CAPI_CALL_H_

#include "ecma/gen/helper/call.h"

#define ECMA_FUNCTION(NAME, RETURN, ...) CREATE_CALLEE(NAME)
#define ECMA_TYPE(TYPENAME, ...) CREATE_CALLEE(Ecma_##TYPENAME##_create)

#include "ecma/runtime/capi.def.h"

#undef ECMA_TYPE
#undef ECMA_FUNCTION

#endif /* ECMA_RUNTIME_CAPI_CALL_H_ */
