; ModuleID = '<stdin>'

%Object = type opaque

@0 = internal unnamed_addr constant [6 x i8] c"write\00"
@1 = internal unnamed_addr constant [6 x i8] c"print\00"
@2 = internal unnamed_addr constant [4 x i8] c"msg\00"
@3 = internal unnamed_addr constant [2 x i8] c"\0A\00"
@4 = internal unnamed_addr constant [3 x i8] c"cb\00"
@5 = internal unnamed_addr constant [8 x i8] c"process\00"
@6 = internal unnamed_addr constant [6 x i8] c"Hello\00"
@7 = internal unnamed_addr constant [8 x i8] c"console\00"
@8 = internal unnamed_addr constant [4 x i8] c"log\00"
@9 = internal unnamed_addr constant [11 x i8] c"Callback: \00"
@10 = internal unnamed_addr constant [5 x i8] c"data\00"
@11 = internal unnamed_addr constant [6 x i8] c"stdio\00"

declare void @Ecma_setProperty(%Object*, i8*, %Object*)

declare %Object* @Ecma_getProperty(%Object*, i8*)

declare void @Ecma_setIndex(%Object*, %Object*, %Object*)

declare %Object* @Ecma_call(%Object*, %Object*, %Object*, i32, %Object**)

declare i1 @Ecma_boolCast(%Object*)

declare %Object* @Ecma_Operator_Plus(%Object*, %Object*)

declare %Object* @Ecma_Object_create()

declare %Object* @Ecma_Integer_create(i32)

declare %Object* @Ecma_Boolean_create(i1)

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Null_create()

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)*)

define i32 @main(i32, i8*) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %2 = call %Object* @Ecma_Null_create()
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @11, i32 0, i32 0), %Object* %2)
  %print = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @print)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @1, i32 0, i32 0), %Object* %print)
  %3 = call %Object* @Ecma_Object_create()
  %4 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @12)
  call void @Ecma_setProperty(%Object* %3, i8* getelementptr inbounds ([4 x i8]* @8, i32 0, i32 0), %Object* %4)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @7, i32 0, i32 0), %Object* %3)
  %process = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @process)
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @5, i32 0, i32 0), %Object* %process)
  %process1 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([8 x i8]* @5, i32 0, i32 0))
  %5 = alloca [2 x %Object*]
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([6 x i8]* @6, i32 0, i32 0))
  %7 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 0
  store %Object* %6, %Object** %7
  %8 = call %Object* @Ecma_Function_create(%Object* (%Object*, %Object*, i32, %Object**)* @13)
  %9 = getelementptr inbounds [2 x %Object*]* %5, i32 0, i32 1
  store %Object* %8, %Object** %9
  %10 = call %Object* @Ecma_Undefined_create()
  %11 = call %Object* @Ecma_call(%Object* %process1, %Object* %env, %Object* %10, i32 2, %Object** %7)
  %12 = call %Object* @Ecma_Integer_create(i32 20)
  %stdio = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([6 x i8]* @11, i32 0, i32 0))
  %13 = call %Object* @Ecma_Integer_create(i32 10)
  call void @Ecma_setIndex(%Object* %stdio, %Object* %13, %Object* %12)
  ret i32 0
}

define %Object* @print(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0), %Object* %4)
  %stdio = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([6 x i8]* @11, i32 0, i32 0))
  %write = call %Object* @Ecma_getProperty(%Object* %stdio, i8* getelementptr inbounds ([6 x i8]* @0, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0))
  %6 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %data, %Object** %6
  %7 = call %Object* @Ecma_call(%Object* %write, %Object* %env, %Object* %stdio, i32 1, %Object** %6)
  %8 = call %Object* @Ecma_Undefined_create()
  ret %Object* %8
}

define internal %Object* @12(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @2, i32 0, i32 0), %Object* %4)
  %print = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([6 x i8]* @1, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %msg = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([4 x i8]* @2, i32 0, i32 0))
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([2 x i8]* @3, i32 0, i32 0))
  %7 = call %Object* @Ecma_Operator_Plus(%Object* %msg, %Object* %6)
  %8 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %7, %Object** %8
  %9 = call %Object* @Ecma_call(%Object* %print, %Object* %env, %Object* %1, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}

define %Object* @process(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0), %Object* %4)
  %5 = getelementptr %Object** %3, i32 1
  %6 = load %Object** %5
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @4, i32 0, i32 0), %Object* %6)
  %console = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([8 x i8]* @7, i32 0, i32 0))
  %log = call %Object* @Ecma_getProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @8, i32 0, i32 0))
  %7 = alloca [1 x %Object*]
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0))
  %8 = getelementptr inbounds [1 x %Object*]* %7, i32 0, i32 0
  store %Object* %data, %Object** %8
  %9 = call %Object* @Ecma_call(%Object* %log, %Object* %env, %Object* %console, i32 1, %Object** %8)
  %cb = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @4, i32 0, i32 0))
  %10 = call i1 @Ecma_boolCast(%Object* %cb)
  br i1 %10, label %then, label %finally

then:                                             ; preds = %bootstrap
  %env1 = call %Object* @Ecma_Object_create()
  %cb2 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([3 x i8]* @4, i32 0, i32 0))
  %11 = alloca [1 x %Object*]
  %data3 = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0))
  %12 = getelementptr inbounds [1 x %Object*]* %11, i32 0, i32 0
  store %Object* %data3, %Object** %12
  %13 = call %Object* @Ecma_Undefined_create()
  %14 = call %Object* @Ecma_call(%Object* %cb2, %Object* %env1, %Object* %13, i32 1, %Object** %12)
  %15 = call %Object* @Ecma_Boolean_create(i1 true)
  br label %UnifiedReturnBlock

finally:                                          ; preds = %bootstrap
  %16 = call %Object* @Ecma_Boolean_create(i1 false)
  br label %UnifiedReturnBlock

UnifiedReturnBlock:                               ; preds = %finally, %then
  %UnifiedRetVal = phi %Object* [ %15, %then ], [ %16, %finally ]
  ret %Object* %UnifiedRetVal
}

define internal %Object* @13(%Object*, %Object*, i32, %Object**) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  %4 = load %Object** %3
  call void @Ecma_setProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0), %Object* %4)
  %console = call %Object* @Ecma_getProperty(%Object* %0, i8* getelementptr inbounds ([8 x i8]* @7, i32 0, i32 0))
  %log = call %Object* @Ecma_getProperty(%Object* %console, i8* getelementptr inbounds ([4 x i8]* @8, i32 0, i32 0))
  %5 = alloca [1 x %Object*]
  %6 = call %Object* @Ecma_String_create(i8* getelementptr inbounds ([11 x i8]* @9, i32 0, i32 0))
  %data = call %Object* @Ecma_getProperty(%Object* %env, i8* getelementptr inbounds ([5 x i8]* @10, i32 0, i32 0))
  %7 = call %Object* @Ecma_Operator_Plus(%Object* %6, %Object* %data)
  %8 = getelementptr inbounds [1 x %Object*]* %5, i32 0, i32 0
  store %Object* %7, %Object** %8
  %9 = call %Object* @Ecma_call(%Object* %log, %Object* %env, %Object* %console, i32 1, %Object** %8)
  %10 = call %Object* @Ecma_Undefined_create()
  ret %Object* %10
}
