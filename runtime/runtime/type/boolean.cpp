#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/boolean.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Boolean *Ecma_Boolean_create(bool value)
{
    return new Boolean(value);
}

std::string Boolean::toString(void) const
{
    return "[Boolean]";
}
