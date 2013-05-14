#include <string>
#include <sstream>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

String *Ecma_String_create(char *value)
{
    return new String(value);
}

Object *String::operatorPlus(Object *other) const
{
    return new String(m_value + other->toString());
}

std::string String::toString(void) const
{
    return m_value;
}
