#include <iostream>
#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/array.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;

extern "C" Object *Ecma_print(Object *env, Object *thisValue, int argc, Object **argv)
{
    if (argc > 0)
    {
        std::cout << argv[0]->toString();
    }
    return Ecma_Undefined_create();
}

extern "C" Object *Ecma_toString(Object *env, Object *thisValue, int argc, Object **argv)
{
    if (argc > 0)
    {
        return new type::String(argv[0]->toString());
    }
    return Ecma_Undefined_create();
}
