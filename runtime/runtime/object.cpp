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

Object *Object::getProperty(const std::string &name) const
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

Object *Object::getIndex(Object *index) const
{
    return Ecma_Undefined_create();
}

Object *Object::call(Object *env, Object *thisValue, int argc, Object **argv)
{
    return Ecma_Undefined_create();
}

bool Object::boolCast(void) const
{
    return true;
}

Object *Object::operatorLogicalOr(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorLogicalAnd(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorBitwiseOr(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorBitwiseXor(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorBitwiseAnd(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorEqual(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorNotEqual(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorIdentity(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorNotIdentity(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorLesser(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorLesserOrEqual(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorGreater(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorGreaterOrEqual(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorInstanceOf(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorIn(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorLeftShift(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorRightShift(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorPlus(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorMinus(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorMul(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorDiv(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorMod(Object *other) const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorNot() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorInv() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorPositive() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorNegative() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorIncrementation() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorDecrementation() const
{
    return Ecma_Undefined_create();
}

Object *Object::operatorTypeOf() const
{
    return new type::String("object");
}
