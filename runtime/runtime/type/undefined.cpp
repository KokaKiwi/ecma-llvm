#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/undefined.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Undefined *Ecma_Undefined_create()
{
    return new Undefined();
}

std::string Undefined::toString(void) const
{
    return "[Undefined]";
}
