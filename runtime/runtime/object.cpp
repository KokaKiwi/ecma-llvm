#include <string>
#include "ecma/runtime/object.h"
#include "ecma/runtime/capi.h"

using namespace ecma;
using namespace ecma::runtime;

Object *Ecma_Object_create()
{
    return new Object();
}

std::string Object::toString(void) const
{
    return "[Object]";
}

void Object::setProperty(const std::string &name, Object *value)
{
    m_properties[name] = value;
}

Object *Object::getProperty(const std::string &name)
{
    auto it = m_properties.find(name);
    if (it != m_properties.end())
    {
        return it->second;
    }

    return Ecma_Undefined_create();
}

void Object::setIndex(Object *index, Object *value)
{

}

Object *Object::getIndex(Object *index)
{
    return Ecma_Undefined_create();
}

Object *Object::call(Object *env, Object *thisValue, int argc, Object **argv)
{
    return Ecma_Undefined_create();
}
