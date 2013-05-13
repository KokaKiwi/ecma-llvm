#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

String *Ecma_String_create(char *value)
{
    return new String(value);
}

std::string String::toString(void) const
{
    return "[String]";
}
