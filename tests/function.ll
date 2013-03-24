; ModuleID = '../tests/function.js'

@0 = private unnamed_addr constant [29 x i8] c"Do you have some Schwepps?\0A\22\00"
@1 = private unnamed_addr constant [6 x i8] c"Test\22\00"
@2 = private unnamed_addr constant [6 x i8] c"test\22\00"

define i32 @main(i32, i8**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = call i32 (...)* @test()
  ret i32 %2
}

define i32 @test(...) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %0 = call i32 (...)* @printf(i8* getelementptr inbounds ([29 x i8]* @0, i32 0, i32 0))
  %1 = call i32 (...)* @strcmp(i8* getelementptr inbounds ([6 x i8]* @1, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8]* @2, i32 0, i32 0))
  ret i32 %1
}

declare i32 @printf(...)

declare i32 @strcmp(...)
