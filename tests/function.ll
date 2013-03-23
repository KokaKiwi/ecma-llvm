; ModuleID = '../tests/function.js'

define i32 @main(i32, i8**) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  %2 = call i32 (...)* @kiwi(i32 10, i32 2)
  %3 = alloca i32
  store i32 %2, i32* %3
  %4 = load i32* %3
  ret i32 %4
}

define i32 @kiwi(...) {
bootstrap:
  br label %entry

entry:                                            ; preds = %bootstrap
  ret i32 20
}
