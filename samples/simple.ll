; ModuleID = '<stdin>'

%Object = type opaque

@0 = internal unnamed_addr constant [11 x i8] c"Ecma_print\00"
@1 = internal unnamed_addr constant [11 x i8] c"Ecma_print\00"
@2 = internal unnamed_addr constant [6 x i8] c"print\00"
@3 = internal unnamed_addr constant [6 x i8] c"print\00"
@4 = internal unnamed_addr constant [13 x i8] c"Hello world!\00"

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare %Object* @Ecma_call(%Object*, %Object*, %Object*, i32, %Object**)

declare %Object* @Ecma_Object_create()

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %Ecma_print = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @Ecma_print)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([11 x i8]* @0, i32 0, i32 0), %Object* %Ecma_print)
  %Ecma_print1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([11 x i8]* @1, i32 0, i32 0))
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @2, i32 0, i32 0), %Object* %Ecma_print1)
  %print = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @3, i32 0, i32 0))
  %2 = alloca [1 x %Object*]
  %3 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([13 x i8]* @4, i32 0, i32 0))
  %4 = getelementptr inbounds [1 x %Object*]* %2, i32 0, i32 0
  store %Object* %3, %Object** %4
  %5 = call %Object* @Ecma_Undefined_create()
  %6 = call %Object* @Ecma_call(%Object* %print, %Object* %env, %Object* %5, i32 1, %Object** %4)
  ret i32 0
}

declare %Object* @Ecma_print(%Object*, %Object*, i32, %Object**)
