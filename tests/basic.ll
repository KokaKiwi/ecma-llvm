; ModuleID = '../tests/basic.js'

%Object = type opaque

@0 = private unnamed_addr constant [6 x i8] c"stdio\00"
@1 = private unnamed_addr constant [5 x i8] c"data\00"
@2 = private unnamed_addr constant [6 x i8] c"stdio\00"
@3 = private unnamed_addr constant [6 x i8] c"write\00"
@4 = private unnamed_addr constant [5 x i8] c"data\00"
@5 = private unnamed_addr constant [6 x i8] c"print\00"
@6 = private unnamed_addr constant [4 x i8] c"msg\00"
@7 = private unnamed_addr constant [6 x i8] c"print\00"
@8 = private unnamed_addr constant [4 x i8] c"msg\00"
@9 = private unnamed_addr constant [2 x i8] c"\0A\00"
@10 = private unnamed_addr constant [4 x i8] c"log\00"
@11 = private unnamed_addr constant [8 x i8] c"console\00"
@12 = private unnamed_addr constant [5 x i8] c"data\00"
@13 = private unnamed_addr constant [3 x i8] c"cb\00"
@14 = private unnamed_addr constant [8 x i8] c"console\00"
@15 = private unnamed_addr constant [4 x i8] c"log\00"
@16 = private unnamed_addr constant [5 x i8] c"data\00"
@17 = private unnamed_addr constant [3 x i8] c"cb\00"
@18 = private unnamed_addr constant [3 x i8] c"cb\00"
@19 = private unnamed_addr constant [5 x i8] c"data\00"
@20 = private unnamed_addr constant [8 x i8] c"process\00"
@21 = private unnamed_addr constant [8 x i8] c"process\00"
@22 = private unnamed_addr constant [6 x i8] c"Hello\00"
@23 = private unnamed_addr constant [5 x i8] c"data\00"
@24 = private unnamed_addr constant [8 x i8] c"console\00"
@25 = private unnamed_addr constant [4 x i8] c"log\00"
@26 = private unnamed_addr constant [11 x i8] c"Callback: \00"
@27 = private unnamed_addr constant [5 x i8] c"data\00"
@28 = private unnamed_addr constant [6 x i8] c"stdio\00"

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare void @Ecma_setIndex(%Object*, %Object*, %Object*)

declare %Object* @Ecma_getIndex(%Object*, %Object*)

declare %Object* @Ecma_call(%Object*, %Object*, %Object*, i32, %Object**)

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

declare %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %env = call %Object* @Ecma_Object_create()
  %2 = call %Object* @Ecma_Null_create()
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @0, i32 0, i32 0), %Object* %2)
  %print = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @print)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @5, i32 0, i32 0), %Object* %print)
  %3 = call %Object* @Ecma_Object_create()
  %4 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @29)
  call void @Ecma_setProperty(%Object* %3, i8* getelementptr inbounds ([4 x i8]* @10, i32 0, i32 0), %Object* %4)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @11, i32 0, i32 0), %Object* %3)
  %process = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @process)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @20, i32 0, i32 0), %Object* %process)
  %process1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @21, i32 0, i32 0))
  %5 = alloca [2 x %Object*]
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([6 x i8]* @22, i32 0, i32 0))
  %7 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 0
  store %Object* %6, %Object** %7
  %8 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @30)
  %9 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 1
  store %Object* %8, %Object** %9
  %10 = call %Object* @Ecma_Undefined_create()
  %11 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 0
  %12 = call %Object* @Ecma_call(%Object* %process1, %Object* %env, %Object* %10, i32 2, %Object** %11)
  %13 = call %Object* @Ecma_Integer_create(i32 20)
  %stdio = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @28, i32 0, i32 0))
  %14 = call %Object* @Ecma_Integer_create(i32 10)
  call void @Ecma_setIndex(%Object* %stdio, %Object* %14, %Object* %13)
  ret i32 0
}

define %Object* @print(%Object*, %Object*, i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %env = call %Object* @Ecma_Object_create()
  %4 = getelementptr %Object** %3, i32 0
  %5 = load %Object** %4
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @1, i32 0, i32 0), %Object* %5)
  %stdio = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([6 x i8]* @2, i32 0, i32 0))
  %write = call %Object* @Ecma_getProperty(%Object* %stdio, i8* getelementptr inbounds ([6 x i8]* @3, i32 0, i32 0))
  %6 = alloca [1 x %Object*]
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @4, i32 0, i32 0))
  %7 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  store %Object* %data, %Object** %7
  %8 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  %9 = call %Object* @Ecma_call(%Object* %write, %Object* %env, %Object* %stdio, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}

define %Object* @29(%Object*, %Object*, i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %env = call %Object* @Ecma_Object_create()
  %4 = getelementptr %Object** %3, i32 0
  %5 = load %Object** %4
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @6, i32 0, i32 0), %Object* %5)
  %print = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([6 x i8]* @7, i32 0, i32 0))
  %6 = alloca [1 x %Object*]
  %msg = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @8, i32 0, i32 0))
  %7 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([2 x i8]* @9, i32 0, i32 0))
  %8 = call %Object* @Ecma_Operator_Plus(%Object* %msg, %Object* %7)
  %9 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  store %Object* %8, %Object** %9
  %10 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  %11 = call %Object* @Ecma_call(%Object* %print, %Object* %env, %Object* %1, i32 1, %Object** %10)
  %12 = call %Object* @Ecma_Undefined_create()
  ret %Object* %12
}

define %Object* @process(%Object*, %Object*, i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %env = call %Object* @Ecma_Object_create()
  %4 = getelementptr %Object** %3, i32 0
  %5 = load %Object** %4
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @12, i32 0, i32 0), %Object* %5)
  %6 = getelementptr %Object** %3, i32 1
  %7 = load %Object** %6
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @13, i32 0, i32 0), %Object* %7)
  %console = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([8 x i8]* @14, i32 0, i32 0))
  %log = call %Object* @Ecma_getProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @15, i32 0, i32 0))
  %8 = alloca [1 x %Object*]
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @16, i32 0, i32 0))
  %9 = getelementptr inbounds [1 x %Object*]* %8, i32 0, i32 0
  store %Object* %data, %Object** %9
  %10 = getelementptr inbounds [1 x %Object*]* %8, i32 0, i32 0
  %11 = call %Object* @Ecma_call(%Object* %log, %Object* %env, %Object* %console, i32 1, %Object** %10)
  %cb = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @17, i32 0, i32 0))
  %12 = call i1 @Ecma_boolCast(%Object* %cb)
  %13 = icmp eq i1 %12, true
  br i1 %13, label %then, label %finally

then:                                             ; preds = %entry
  %env1 = call %Object* @Ecma_Object_create()
  %cb2 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @18, i32 0, i32 0))
  %14 = alloca [1 x %Object*]
  %data3 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @19, i32 0, i32 0))
  %15 = getelementptr inbounds [1 x %Object*]* %14, i32 0, i32 0
  store %Object* %data3, %Object** %15
  %16 = call %Object* @Ecma_Undefined_create()
  %17 = getelementptr inbounds [1 x %Object*]* %14, i32 0, i32 0
  %18 = call %Object* @Ecma_call(%Object* %cb2, %Object* %env1, %Object* %16, i32 1, %Object** %17)
  %19 = call %Object* @Ecma_Boolean_create(i1 true)
  ret %Object* %19

finally:                                          ; preds = %entry
  %20 = call %Object* @Ecma_Boolean_create(i1 false)
  ret %Object* %20
}

define %Object* @30(%Object*, %Object*, i32, %Object**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %env = call %Object* @Ecma_Object_create()
  %4 = getelementptr %Object** %3, i32 0
  %5 = load %Object** %4
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @23, i32 0, i32 0), %Object* %5)
  %console = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([8 x i8]* @24, i32 0, i32 0))
  %log = call %Object* @Ecma_getProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @25, i32 0, i32 0))
  %6 = alloca [1 x %Object*]
  %7 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([11 x i8]* @26, i32 0, i32 0))
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @27, i32 0, i32 0))
  %8 = call %Object* @Ecma_Operator_Plus(%Object* %7, %Object* %data)
  %9 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  store %Object* %8, %Object** %9
  %10 = getelementptr inbounds [1 x %Object*]* %6, i32 0, i32 0
  %11 = call %Object* @Ecma_call(%Object* %log, %Object* %env, %Object* %console, i32 1, %Object** %10)
  %12 = call %Object* @Ecma_Undefined_create()
  ret %Object* %12
}
