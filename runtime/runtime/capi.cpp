#include <cstdlib>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/integer.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;

void *Ecma_malloc(unsigned int size, unsigned int count)
{
    return malloc(size * count);
}

Object *Ecma_Object_create()
{
    return new Object();
}
