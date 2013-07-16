; ModuleID = '<stdin>'

%Object = type opaque

@0 = internal unnamed_addr constant [6 x i8] c"print\00"
@1 = internal unnamed_addr constant [4 x i8] c"msg\00"
@2 = internal unnamed_addr constant [2 x i8] c"\0A\00"
@3 = internal unnamed_addr constant [7 x i8] c"length\00"
@4 = internal unnamed_addr constant [3 x i8] c"cb\00"
@5 = internal unnamed_addr constant [5 x i8] c"data\00"
@6 = internal unnamed_addr constant [2 x i8] c"i\00"
@7 = internal unnamed_addr constant [3 x i8] c"fn\00"
@8 = internal unnamed_addr constant [8 x i8] c"console\00"
@9 = internal unnamed_addr constant [4 x i8] c"log\00"
@10 = internal unnamed_addr constant [5 x i8] c"item\00"

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare %Object* @Ecma_getIndex(%Object*, %Object*)

declare %Object* @Ecma_call(%Object*, %Object*, %Object*, i32, %Object**)

declare i1 @Ecma_boolCast(%Object*)

declare %Object* @Ecma_Operator_Lesser(%Object*, %Object*)

declare %Object* @Ecma_Operator_Plus(%Object*, %Object*)

declare %Object* @Ecma_Object_create()

declare %Object* @Ecma_Array_create(i32, %Object**)

declare %Object* @Ecma_Integer_create(i32)

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %print = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @Ecma_print)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @0, i32 0, i32 0), %Object* %print)
  %console = call %Object* @Ecma_Object_create()
  %2 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @11)
  call void @Ecma_setProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @9, i32 0, i32 0), %Object* %2)
  %3 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @12)
  call void @Ecma_setProperty(%Object* %console, i8* getelementptr inbounds ([3 x i8]* @7, i32 0, i32 0), %Object* %3)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @8, i32 0, i32 0), %Object* %console)
  %console1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @8, i32 0, i32 0))
  %fn = call %Object* @Ecma_getProperty(%Object* %console1, i8* getelementptr inbounds ([3 x i8]* @7, i32 0, i32 0))
  %4 = alloca [2 x %Object*]
  %5 = alloca [3 x %Object*]
  %6 = call %Object* @Ecma_Integer_create(i32 1)
  %7 = getelementptr inbounds [3 x %Object*]* %5, i32 0, i32 0
  store %Object* %6, %Object** %7
  %8 = call %Object* @Ecma_Integer_create(i32 2)
  %9 = getelementptr inbounds [3 x %Object*]* %5, i32 0, i32 1
  store %Object* %8, %Object** %9
  %10 = call %Object* @Ecma_Integer_create(i32 3)
  %11 = getelementptr inbounds [3 x %Object*]* %5, i32 0, i32 2
  store %Object* %10, %Object** %11
  %12 = call %Object* @Ecma_Array_create(i32 3, %Object** %7)
  %13 = getelementptr inbounds [2 x %Object*]* %4, i32 0, i32 0
  store %Object* %12, %Object** %13
  %14 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @13)
  %15 = getelementptr inbounds [2 x %Object*]* %4, i32 0, i32 1
  store %Object* %14, %Object** %15
  %16 = call %Object* @Ecma_call(%Object* %fn, %Object* %env, %Object* %console1, i32 2, %Object** %13)
  ret i32 0
}

declare %Object* @Ecma_print(%Object*, %Object*, i32, %Object**)

define internal %Object* @11(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @1, i32 0, i32 0), %Object* %4)
  %print = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([6 x i8]* @0, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %msg = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @1, i32 0, i32 0))
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([2 x i8]* @2, i32 0, i32 0))
  %7 = call %Object* @Ecma_Operator_Plus(%Object* %msg, %Object* %6)
  %8 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %7, %Object** %8
  %9 = call %Object* @Ecma_call(%Object* %print, %Object* %env, %Object* %1, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}

define internal %Object* @12(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @5, i32 0, i32 0), %Object* %4)
  %5 = getelementptr %Object** %3, i32 1
  %6 = load %Object** %5
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @4, i32 0, i32 0), %Object* %6)
  %i = call %Object* @Ecma_Integer_create(i32 0)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([2 x i8]* @6, i32 0, i32 0), %Object* %i)
  br label %test

test:                                             ; preds = %then, %bootstrap
  %i1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([2 x i8]* @6, i32 0, i32 0))
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @5, i32 0, i32 0))
  %length = call %Object* @Ecma_getProperty(%Object* %data, i8* getelementptr inbounds ([7 x i8]* @3, i32 0, i32 0))
  %7 = call %Object* @Ecma_Operator_Lesser(%Object* %i1, %Object* %length)
  %8 = call i1 @Ecma_boolCast(%Object* %7)
  br i1 %8, label %then, label %finally

then:                                             ; preds = %test
  %env2 = call %Object* @Ecma_Object_create()
  %cb = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @4, i32 0, i32 0))
  %9 = alloca [1 x %Object*]
  %data3 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @5, i32 0, i32 0))
  %i4 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([2 x i8]* @6, i32 0, i32 0))
  %10 = call %Object* @Ecma_getIndex(%Object* %data3, %Object* %i4)
  %11 = getelementptr inbounds [1 x %Object*]* %9, i32 0, i32 0
  store %Object* %10, %Object** %11
  %12 = call %Object* @Ecma_Undefined_create()
  %13 = call %Object* @Ecma_call(%Object* %cb, %Object* %env2, %Object* %12, i32 1, %Object** %11)
  br label %test

finally:                                          ; preds = %test
  %14 = call %Object* @Ecma_Undefined_create()
  ret %Object* %14
}

define internal %Object* @13(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0), %Object* %4)
  %console = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([8 x i8]* @8, i32 0, i32 0))
  %log = call %Object* @Ecma_getProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @9, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %item = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0))
  %6 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %item, %Object** %6
  %7 = call %Object* @Ecma_call(%Object* %log, %Object* %env, %Object* %console, i32 1, %Object** %6)
  %8 = call %Object* @Ecma_Undefined_create()
  ret %Object* %8
}
