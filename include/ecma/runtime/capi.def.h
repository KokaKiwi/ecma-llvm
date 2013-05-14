// Base functions
ECMA_FUNCTION(Ecma_setProperty, void, ecma::runtime::Object *instance, char *name, ecma::runtime::Object *value)
ECMA_FUNCTION(Ecma_getProperty, ecma::runtime::Object *, ecma::runtime::Object *instance, char *name)

ECMA_FUNCTION(Ecma_setIndex, void, ecma::runtime::Object *instance, ecma::runtime::Object *index, ecma::runtime::Object *value)
ECMA_FUNCTION(Ecma_getIndex, ecma::runtime::Object *, ecma::runtime::Object *instance, ecma::runtime::Object *index)

ECMA_FUNCTION(Ecma_call, ecma::runtime::Object *, ecma::runtime::Object *callee, ecma::runtime::Object *env, ecma::runtime::Object *thisValue, int argc, ecma::runtime::Object **argv)

ECMA_FUNCTION(Ecma_boolCast, bool, ecma::runtime::Object *object)

ECMA_FUNCTION(Ecma_toString, ecma::runtime::Object *, ecma::runtime::Object *object)

ECMA_FUNCTION(Ecma_Operator_LogicalOr, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_LogicalAnd, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_BitwiseOr, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_BitwiseXor, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_BitwiseAnd, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Equal, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_NotEqual, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Identity, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_NotIdentity, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Lesser, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_LesserOrEqual, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Greater, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_GreaterOrEqual, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_InstanceOf, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_In, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_LeftShift, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_RightShift, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Plus, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Minus, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Mul, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Div, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Mod, ecma::runtime::Object *, ecma::runtime::Object *, ecma::runtime::Object *)

ECMA_FUNCTION(Ecma_Operator_Not, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Inv, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Positive, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Negative, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Incrementation, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_Decrementation, ecma::runtime::Object *, ecma::runtime::Object *)
ECMA_FUNCTION(Ecma_Operator_TypeOf, ecma::runtime::Object *, ecma::runtime::Object *)

// Object type
ECMA_FUNCTION(Ecma_Object_create, ecma::runtime::Object *)

// Array type
ECMA_TYPE(Array, int size, ecma::runtime::Object **elems)

// Integer type
ECMA_TYPE(Integer, int value)

// Boolean type
ECMA_TYPE(Boolean, bool value)

// String type
ECMA_TYPE(String, char *value)

// Null type
ECMA_TYPE(Null)

// Undefined type
ECMA_TYPE(Undefined)

// Function type
ECMA_TYPE(Function, ecma::runtime::type::Function::Signature)
