; ModuleID = '../tests/basic.js'

%Object = type opaque

@0 = private unnamed_addr constant [13 x i8] c"Hello world!\00"

declare i8* @Ecma_malloc(i32, i32)

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare void @Ecma_setIndex(%Object*, %Object*, %Object*)

declare %Object* @Ecma_getIndex(%Object*, %Object*)

declare %Object* @Ecma_call(%Object*, i32, %Object**)

declare i1 @Ecma_boolCast(%Object*)

declare %Object* @Ecma_Operator_LogicalOr(%Object*, %Object*)

declare %Object* @Ecma_Operator_LogicalAnd(%Object*, %Object*)

declare %Object* @Ecma_Operator_BitwiseOr(%Object*, %Object*)

declare %Object* @Ecma_Operator_BitwiseXor(%Object*, %Object*)

declare %Object* @Ecma_Operator_BitwiseAnd(%Object*, %Object*)

declare %Object* @Ecma_Operator_Equal(%Object*, %Object*)

declare %Object* @Ecma_Operator_NotEqual(%Object*, %Object*)

declare %Object* @Ecma_Operator_Identity(%Object*, %Object*)

declare %Object* @Ecma_Operator_NotIdentity(%Object*, %Object*)

declare %Object* @Ecma_Operator_Lesser(%Object*, %Object*)

declare %Object* @Ecma_Operator_LesserOrEqual(%Object*, %Object*)

declare %Object* @Ecma_Operator_Greater(%Object*, %Object*)

declare %Object* @Ecma_Operator_GreaterOrEqual(%Object*, %Object*)

declare %Object* @Ecma_Operator_InstanceOf(%Object*, %Object*)

declare %Object* @Ecma_Operator_In(%Object*, %Object*)

declare %Object* @Ecma_Operator_LeftShift(%Object*, %Object*)

declare %Object* @Ecma_Operator_RightShift(%Object*, %Object*)

declare %Object* @Ecma_Operator_Plus(%Object*, %Object*)

declare %Object* @Ecma_Operator_Minus(%Object*, %Object*)

declare %Object* @Ecma_Operator_Mul(%Object*, %Object*)

declare %Object* @Ecma_Operator_Div(%Object*, %Object*)

declare %Object* @Ecma_Operator_Mod(%Object*, %Object*)

declare %Object* @Ecma_Operator_Not(%Object*)

declare %Object* @Ecma_Operator_Inv(%Object*)

declare %Object* @Ecma_Operator_Positive(%Object*)

declare %Object* @Ecma_Operator_Negative(%Object*)

declare %Object* @Ecma_Operator_Incrementation(%Object*)

declare %Object* @Ecma_Operator_Decrementation(%Object*)

declare %Object* @Ecma_Operator_TypeOf(%Object*)

declare %Object* @Ecma_Object_create()

declare %Object* @Ecma_Array_create(i32, %Object**)

declare %Object* @Ecma_Integer_create(i32)

declare %Object* @Ecma_Boolean_create(i1)

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Null_create()

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @swap)
  %swap = alloca %Object*
  store %Object* %2, %Object** %swap
  %3 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @index)
  %index = alloca %Object*
  store %Object* %3, %Object** %index
  %4 = alloca [8 x %Object*]
  %5 = call %Object* @Ecma_Integer_create(i32 0)
  %6 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 0
  store %Object* %5, %Object** %6
  %7 = call %Object* @Ecma_Integer_create(i32 0)
  %8 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 1
  store %Object* %7, %Object** %8
  %9 = call %Object* @Ecma_Integer_create(i32 0)
  %10 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 2
  store %Object* %9, %Object** %10
  %11 = call %Object* @Ecma_Integer_create(i32 0)
  %12 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 3
  store %Object* %11, %Object** %12
  %13 = call %Object* @Ecma_Integer_create(i32 0)
  %14 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 4
  store %Object* %13, %Object** %14
  %15 = call %Object* @Ecma_Integer_create(i32 0)
  %16 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 5
  store %Object* %15, %Object** %16
  %17 = call %Object* @Ecma_Integer_create(i32 0)
  %18 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 6
  store %Object* %17, %Object** %18
  %19 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([13 x i8]* @0, i32 0, i32 0))
  %20 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 7
  store %Object* %19, %Object** %20
  %21 = getelementptr inbounds [8 x %Object*]* %4, i32 0, i32 0
  %22 = call %Object* @Ecma_Array_create(i32 8, %Object** %21)
  %tab = alloca %Object*
  store %Object* %22, %Object** %tab
  ret i32 0
}

define %Object* @swap(i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = getelementptr %Object** %1, i32 0
  %3 = load %Object** %2
  %elems = alloca %Object*
  store %Object* %3, %Object** %elems
  %elems1 = load %Object** %elems
  %4 = call %Object* @Ecma_Integer_create(i32 0)
  %5 = call %Object* @Ecma_getIndex(%Object* %elems1, %Object* %4)
  %tmp = alloca %Object*
  store %Object* %5, %Object** %tmp
  %elems2 = load %Object** %elems
  %6 = call %Object* @Ecma_Integer_create(i32 1)
  %7 = call %Object* @Ecma_getIndex(%Object* %elems2, %Object* %6)
  %elems3 = load %Object** %elems
  %8 = call %Object* @Ecma_Integer_create(i32 0)
  call void @Ecma_setIndex(%Object* %elems3, %Object* %8, %Object* %7)
  %tmp4 = load %Object** %tmp
  %elems5 = load %Object** %elems
  %9 = call %Object* @Ecma_Integer_create(i32 1)
  call void @Ecma_setIndex(%Object* %elems5, %Object* %9, %Object* %tmp4)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}

define %Object* @index(i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = call %Object* @Ecma_Integer_create(i32 2)
  ret %Object* %2
}
