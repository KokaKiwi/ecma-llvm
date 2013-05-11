#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/integer.h"

using namespace ecma;
using namespace ecma::runtime;

type::Integer *Ecma_Integer_create(int value)
{
    return new type::Integer(value);
}
