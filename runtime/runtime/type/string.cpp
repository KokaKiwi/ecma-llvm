#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;

type::String *Ecma_String_create(char *value)
{
    return new type::String(value);
}
