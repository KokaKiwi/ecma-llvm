; ModuleID = '<stdin>'

%Object = type opaque

declare %Object* @Ecma_Object_create()

define i32 @main(i32, i8*) {
bootstrap:
  %env = call %Object* @Ecma_Object_create()
  ret i32 0
}
