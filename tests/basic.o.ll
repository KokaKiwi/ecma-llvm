; ModuleID = '../tests/basic.ll'

%Object = type opaque

@0 = internal unnamed_addr constant [13 x i8] c"Hello world!\00"

declare void @Ecma_setIndex(%Object*, %Object*, %Object*)

declare %Object* @Ecma_getIndex(%Object*, %Object*)

declare %Object* @Ecma_Array_create(i32, %Object**)

declare %Object* @Ecma_Integer_create(i32)

declare %Object* @Ecma_String_create(i8*)

declare %Object* @Ecma_Undefined_create()

declare %Object* @Ecma_Function_create(%Object* (i32, %Object**)*)

define i32 @main(i32, i8* nocapture) {
bootstrap:
  %2 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @swap)
  %3 = call %Object* @Ecma_Function_create(%Object* (i32, %Object**)* @index)
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
  %21 = call %Object* @Ecma_Array_create(i32 8, %Object** %6)
  ret i32 0
}

define %Object* @swap(i32, %Object** nocapture) {
bootstrap:
  %2 = load %Object** %1
  %3 = call %Object* @Ecma_Integer_create(i32 0)
  %4 = call %Object* @Ecma_getIndex(%Object* %2, %Object* %3)
  %5 = call %Object* @Ecma_Integer_create(i32 1)
  %6 = call %Object* @Ecma_getIndex(%Object* %2, %Object* %5)
  %7 = call %Object* @Ecma_Integer_create(i32 0)
  call void @Ecma_setIndex(%Object* %2, %Object* %7, %Object* %6)
  %8 = call %Object* @Ecma_Integer_create(i32 1)
  call void @Ecma_setIndex(%Object* %2, %Object* %8, %Object* %4)
  %9 = call %Object* @Ecma_Undefined_create()
  ret %Object* %9
}

define %Object* @index(i32, %Object** nocapture) {
bootstrap:
  %2 = tail call %Object* @Ecma_Integer_create(i32 2)
  ret %Object* %2
}
