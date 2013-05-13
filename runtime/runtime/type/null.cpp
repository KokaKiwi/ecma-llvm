#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/null.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Null *Ecma_Null_create()
{
    return new Null();
}

std::string Null::toString(void) const
{
    return "[Null]";
}
