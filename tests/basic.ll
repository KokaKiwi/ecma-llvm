; ModuleID = '../tests/basic.js'

%Object = type opaque

@0 = private unnamed_addr constant [4 x i8] c"log\00"
@1 = private unnamed_addr constant [4 x i8] c"log\00"
@2 = private unnamed_addr constant [9 x i8] c"CALLBACK\00"

declare i8* @Ecma_malloc(i32, i32)

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare %Object* @Ecma_call(%Object*, i32, %Object**)

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

declare %Object* @Ecma_Object_create()

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
  %2 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @process)
  %3 = alloca %Object*
  store %Object* %2, %Object** %3
  %4 = load %Object** %3
  %5 = alloca [2 x %Object*]
  %6 = call %Object* @Ecma_Integer_create(i32 25)
  %7 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 0
  store %Object* %6, %Object** %7
  %8 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @_INLINE_0_)
  %9 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 1
  store %Object* %8, %Object** %9
  %10 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 0
  %11 = call %Object* @Ecma_call(%Object* %4, i32 2, %Object** %10)
  ret i32 0
}

define %Object* @process(i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = getelementptr %Object** %1, i32 0
  %3 = load %Object** %2
  %4 = alloca %Object*
  store %Object* %3, %Object** %4
  %5 = getelementptr %Object** %1, i32 1
  %6 = load %Object** %5
  %7 = alloca %Object*
  store %Object* %6, %Object** %7
  %8 = alloca %Object*
  %9 = load %Object** %8
  %10 = call %Object* @Ecma_getProperty(%Object* %9, i8* getelementptr inbounds ([4 x i8]* @0, i32 0, i32 0))
  %11 = alloca [1 x %Object*]
  %12 = load %Object** %4
  %13 = getelementptr inbounds [1 x %Object*]* %11, i32 0, i32 0
  store %Object* %12, %Object** %13
  %14 = getelementptr inbounds [1 x %Object*]* %11, i32 0, i32 0
  %15 = call %Object* @Ecma_call(%Object* %10, i32 1, %Object** %14)
  %16 = load %Object** %7
  %17 = alloca [1 x %Object*]
  %18 = load %Object** %4
  %19 = getelementptr inbounds [1 x %Object*]* %17, i32 0, i32 0
  store %Object* %18, %Object** %19
  %20 = getelementptr inbounds [1 x %Object*]* %17, i32 0, i32 0
  %21 = call %Object* @Ecma_call(%Object* %16, i32 1, %Object** %20)
  %22 = call %Object* @Ecma_Undefined_create()
  ret %Object* %22
}

define %Object* @_INLINE_0_(i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = alloca %Object*
  %3 = load %Object** %2
  %4 = call %Object* @Ecma_getProperty(%Object* %3, i8* getelementptr inbounds ([4 x i8]* @1, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([9 x i8]* @2, i32 0, i32 0))
  %7 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %6, %Object** %7
  %8 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  %9 = call %Object* @Ecma_call(%Object* %4, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}
