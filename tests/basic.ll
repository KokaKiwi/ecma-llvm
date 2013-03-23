; ModuleID = '../tests/basic.js'

@0 = private unnamed_addr constant [10 x i8] c"LOL kiwi.\00"
@1 = private unnamed_addr constant [17 x i8] c"LOL message: %s\0A\00"

define i32 @main(i32, i8**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = alloca i32
  store i32 20, i32* %2
  %3 = alloca i8*
  store i8* getelementptr inbounds ([10 x i8]* @0, i32 0, i32 0), i8** %3
  %4 = load i32* %2
  %5 = mul i32 30, %4
  %6 = alloca i32
  store i32 %5, i32* %6
  %7 = load i8** %3
  %8 = call i32 (...)* @printf(i8* getelementptr inbounds ([17 x i8]* @1, i32 0, i32 0), i8* %7)
  %9 = load i32* %2
  %10 = add i32 %9, 1
  ret i32 %10
}

declare i32 @printf(...)
