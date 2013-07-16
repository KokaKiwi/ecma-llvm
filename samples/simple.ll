; ModuleID = '<stdin>'

%Object = type opaque

@0 = internal unnamed_addr constant [11 x i8] c"Ecma_print\00"
@1 = internal unnamed_addr constant [6 x i8] c"print\00"
@2 = internal unnamed_addr constant [13 x i8] c"Hello world!\00"
@3 = internal unnamed_addr constant [2 x i8] c"\0A\00"
@4 = internal unnamed_addr constant [5 x i8] c"test\00"

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare %Object* @Ecma_call(%Object*, %Object*, %Object*, i32, %Object**)

declare %Object* @Ecma_Operator_Plus(%Object*, %Object*)

declare %Object* @Ecma_Object_create()

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %test = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @5)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @4, i32 0, i32 0), %Object* %test)
  %test1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @4, i32 0, i32 0))
  %2 = alloca [0 x %Object*]
  %3 = call %Object* @Ecma_Undefined_create()
  %4 = getelementptr inbounds [0 x %Object*]* %2, i32 0, i32 0
  %5 = call %Object* @Ecma_call(%Object* %test1, %Object* %env, %Object* %3, i32 0, %Object** %4)
  ret i32 0
}

define internal %Object* @5(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %Ecma_print = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @Ecma_print)
  call void @Ecma_setProperty(%Object* %0, i8* getelementptr inbounds ([11 x i8]* @0, i32 0, i32 0), %Object* %Ecma_print)
  %print = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([11 x i8]* @0, i32 0, i32 0))
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @1, i32 0, i32 0), %Object* %print)
  %print2 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @1, i32 0, i32 0))
  %4 = alloca [1 x %Object*]
  %5 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([13 x i8]* @2, i32 0, i32 0))
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([2 x i8]* @3, i32 0, i32 0))
  %7 = call %Object* @Ecma_Operator_Plus(%Object* %5, %Object* %6)
  %8 = getelementptr inbounds [1 x %Object*]* %4, i32 0, i32 0
  store %Object* %7, %Object** %8
  %9 = call %Object* @Ecma_call(%Object* %print2, %Object* %env, %Object* %1, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}

declare %Object* @Ecma_print(%Object*, %Object*, i32, %Object**)
