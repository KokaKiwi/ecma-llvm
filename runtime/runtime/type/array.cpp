#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/array.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Array *Ecma_Array_create(int size, Object **elems)
{
    return new Array(size, elems);
}

std::string Array::toString(void) const
{
    return "[Array]";
}
