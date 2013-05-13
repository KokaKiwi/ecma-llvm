#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/type/function.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Function *Ecma_Function_create(type::Function::Signature fn)
{
    return new Function(fn);
}

std::string Function::toString(void) const
{
    return "[Function]";
}

Object *Function::call(Object *env, Object *thisValue, int argc, Object **argv)
{
    return m_ptr(env, thisValue, argc, argv);
}
