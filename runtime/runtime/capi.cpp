#include <iostream>
#include <string>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/array.h"
#include "ecma/runtime/type/string.h"

using namespace ecma;
using namespace ecma::runtime;

void Ecma_setProperty(Object *instance, char *name, Object *value)
{
    instance->setProperty(name, value);
}
Object *Ecma_getProperty(Object *instance, char *name)
{
    return instance->getProperty(name);
}

void Ecma_setIndex(Object *instance, Object *index, Object *value)
{
    instance->setIndex(index, value);
}
Object *Ecma_getIndex(Object *instance, Object *index)
{
    return instance->getIndex(index);
}

Object *Ecma_call(Object *callee, Object *env, Object *thisValue, int argc, Object **argv)
{
    return callee->call(env, thisValue, argc, argv);
}

bool Ecma_boolCast(Object *object)
{
    return object->boolCast();
}

Object *Ecma_toString(Object *object)
{
    return new type::String(object->toString());
}

Object *Ecma_Operator_LogicalOr(Object *left, Object *right)
{
    return left->operatorLogicalOr(right);
}
Object *Ecma_Operator_LogicalAnd(Object *left, Object *right)
{
    return left->operatorLogicalAnd(right);
}
Object *Ecma_Operator_BitwiseOr(Object *left, Object *right)
{
    return left->operatorBitwiseOr(right);
}
Object *Ecma_Operator_BitwiseXor(Object *left, Object *right)
{
    return left->operatorBitwiseXor(right);
}
Object *Ecma_Operator_BitwiseAnd(Object *left, Object *right)
{
    return left->operatorBitwiseAnd(right);
}
Object *Ecma_Operator_Equal(Object *left, Object *right)
{
    return left->operatorEqual(right);
}
Object *Ecma_Operator_NotEqual(Object *left, Object *right)
{
    return left->operatorNotEqual(right);
}
Object *Ecma_Operator_Identity(Object *left, Object *right)
{
    return left->operatorIdentity(right);
}
Object *Ecma_Operator_NotIdentity(Object *left, Object *right)
{
    return left->operatorNotIdentity(right);
}
Object *Ecma_Operator_Lesser(Object *left, Object *right)
{
    return left->operatorLesser(right);
}
Object *Ecma_Operator_LesserOrEqual(Object *left, Object *right)
{
    return left->operatorLesserOrEqual(right);
}
Object *Ecma_Operator_Greater(Object *left, Object *right)
{
    return left->operatorGreater(right);
}
Object *Ecma_Operator_GreaterOrEqual(Object *left, Object *right)
{
    return left->operatorGreaterOrEqual(right);
}
Object *Ecma_Operator_InstanceOf(Object *left, Object *right)
{
    return left->operatorInstanceOf(right);
}
Object *Ecma_Operator_In(Object *left, Object *right)
{
    return left->operatorIn(right);
}
Object *Ecma_Operator_LeftShift(Object *left, Object *right)
{
    return left->operatorLeftShift(right);
}
Object *Ecma_Operator_RightShift(Object *left, Object *right)
{
    return left->operatorRightShift(right);
}
Object *Ecma_Operator_Plus(Object *left, Object *right)
{
    return left->operatorPlus(right);
}
Object *Ecma_Operator_Minus(Object *left, Object *right)
{
    return left->operatorMinus(right);
}
Object *Ecma_Operator_Mul(Object *left, Object *right)
{
    return left->operatorMul(right);
}
Object *Ecma_Operator_Div(Object *left, Object *right)
{
    return left->operatorDiv(right);
}
Object *Ecma_Operator_Mod(Object *left, Object *right)
{
    return left->operatorMod(right);
}

Object *Ecma_Operator_Not(Object *object)
{
    return object->operatorNot();
}
Object *Ecma_Operator_Inv(Object *object)
{
    return object->operatorInv();
}
Object *Ecma_Operator_Positive(Object *object)
{
    return object->operatorPositive();
}
Object *Ecma_Operator_Negative(Object *object)
{
    return object->operatorNegative();
}
Object *Ecma_Operator_Incrementation(Object *object)
{
    return object->operatorIncrementation();
}
Object *Ecma_Operator_Decrementation(Object *object)
{
    return object->operatorDecrementation();
}
Object *Ecma_Operator_TypeOf(Object *object)
{
    return object->operatorTypeOf();
}

extern "C" Object *Ecma_print(Object *env, Object *thisValue, int argc, Object **argv)
{
    if (argc > 0)
    {
        std::cout << argv[0]->toString();
    }
    return Ecma_Undefined_create();
}
