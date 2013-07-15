	.file	"../tests/basic.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%r15
.Ltmp4:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp5:
	.cfi_def_cfa_offset 24
	pushq	%rbx
.Ltmp6:
	.cfi_def_cfa_offset 32
	subq	$16, %rsp
.Ltmp7:
	.cfi_def_cfa_offset 48
.Ltmp8:
	.cfi_offset %rbx, -32
.Ltmp9:
	.cfi_offset %r14, -24
.Ltmp10:
	.cfi_offset %r15, -16
	callq	Ecma_Object_create
	movq	%rax, %r15
	callq	Ecma_Null_create
	movq	%r15, %rdi
	movl	$.L__unnamed_1, %esi
	movq	%rax, %rdx
	callq	Ecma_setProperty
	movl	$print, %edi
	callq	Ecma_Function_create
	movq	%r15, %rdi
	movl	$.L__unnamed_2, %esi
	movq	%rax, %rdx
	callq	Ecma_setProperty
	callq	Ecma_Object_create
	movq	%rax, %rbx
	movl	$__unnamed_3, %edi
	callq	Ecma_Function_create
	movq	%rbx, %rdi
	movl	$.L__unnamed_4, %esi
	movq	%rax, %rdx
	callq	Ecma_setProperty
	movq	%r15, %rdi
	movl	$.L__unnamed_5, %esi
	movq	%rbx, %rdx
	callq	Ecma_setProperty
	movl	$process, %edi
	callq	Ecma_Function_create
	movq	%r15, %rdi
	movl	$.L__unnamed_6, %esi
	movq	%rax, %rdx
	callq	Ecma_setProperty
	movq	%r15, %rdi
	movl	$.L__unnamed_7, %esi
	callq	Ecma_getProperty
	movq	%rax, %r14
	movl	$.L__unnamed_8, %edi
	callq	Ecma_String_create
	movq	%rax, (%rsp)
	movl	$__unnamed_9, %edi
	callq	Ecma_Function_create
	leaq	(%rsp), %rbx
	movq	%rax, 8(%rsp)
	callq	Ecma_Undefined_create
	movq	%r14, %rdi
	movq	%r15, %rsi
	movq	%rax, %rdx
	movl	$2, %ecx
	movq	%rbx, %r8
	callq	Ecma_call
	movl	$20, %edi
	callq	Ecma_Integer_create
	movq	%rax, %r14
	movq	%r15, %rdi
	movl	$.L__unnamed_10, %esi
	callq	Ecma_getProperty
	movq	%rax, %rbx
	movl	$10, %edi
	callq	Ecma_Integer_create
	movq	%rbx, %rdi
	movq	%rax, %rsi
	movq	%r14, %rdx
	callq	Ecma_setIndex
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	ret
.Ltmp11:
	.size	main, .Ltmp11-main
	.cfi_endproc

	.globl	print
	.align	16, 0x90
	.type	print,@function
print:                                  # @print
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%r15
.Ltmp16:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp17:
	.cfi_def_cfa_offset 24
	pushq	%rbx
.Ltmp18:
	.cfi_def_cfa_offset 32
	subq	$16, %rsp
.Ltmp19:
	.cfi_def_cfa_offset 48
.Ltmp20:
	.cfi_offset %rbx, -32
.Ltmp21:
	.cfi_offset %r14, -24
.Ltmp22:
	.cfi_offset %r15, -16
	movq	%rcx, %r15
	movq	%rdi, %r14
	callq	Ecma_Object_create
	movq	%rax, %rbx
	movq	(%r15), %rdx
	movq	%rbx, %rdi
	movl	$.L__unnamed_11, %esi
	callq	Ecma_setProperty
	movq	%r14, %rdi
	movl	$.L__unnamed_12, %esi
	callq	Ecma_getProperty
	movq	%rax, %r14
	movq	%r14, %rdi
	movl	$.L__unnamed_13, %esi
	callq	Ecma_getProperty
	movq	%rax, %r15
	movq	%rbx, %rdi
	movl	$.L__unnamed_14, %esi
	callq	Ecma_getProperty
	leaq	8(%rsp), %r8
	movq	%rax, 8(%rsp)
	movq	%r15, %rdi
	movq	%rbx, %rsi
	movq	%r14, %rdx
	movl	$1, %ecx
	callq	Ecma_call
	callq	Ecma_Undefined_create
	addq	$16, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	ret
.Ltmp23:
	.size	print, .Ltmp23-print
	.cfi_endproc

	.globl	__unnamed_3
	.align	16, 0x90
	.type	__unnamed_3,@function
__unnamed_3:                            # @29
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%r15
.Ltmp30:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp31:
	.cfi_def_cfa_offset 24
	pushq	%r13
.Ltmp32:
	.cfi_def_cfa_offset 32
	pushq	%r12
.Ltmp33:
	.cfi_def_cfa_offset 40
	pushq	%rbx
.Ltmp34:
	.cfi_def_cfa_offset 48
	subq	$16, %rsp
.Ltmp35:
	.cfi_def_cfa_offset 64
.Ltmp36:
	.cfi_offset %rbx, -48
.Ltmp37:
	.cfi_offset %r12, -40
.Ltmp38:
	.cfi_offset %r13, -32
.Ltmp39:
	.cfi_offset %r14, -24
.Ltmp40:
	.cfi_offset %r15, -16
	movq	%rcx, %rbx
	movq	%rsi, %r14
	movq	%rdi, %r15
	callq	Ecma_Object_create
	movq	%rax, %r13
	movq	(%rbx), %rdx
	movq	%r13, %rdi
	movl	$.L__unnamed_15, %esi
	callq	Ecma_setProperty
	movq	%r15, %rdi
	movl	$.L__unnamed_16, %esi
	callq	Ecma_getProperty
	movq	%rax, %r15
	movq	%r13, %rdi
	movl	$.L__unnamed_17, %esi
	callq	Ecma_getProperty
	movq	%rax, %r12
	movl	$.L__unnamed_18, %edi
	callq	Ecma_String_create
	movq	%r12, %rdi
	movq	%rax, %rsi
	callq	Ecma_Operator_Plus
	leaq	8(%rsp), %r8
	movq	%rax, 8(%rsp)
	movq	%r15, %rdi
	movq	%r13, %rsi
	movq	%r14, %rdx
	movl	$1, %ecx
	callq	Ecma_call
	callq	Ecma_Undefined_create
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.Ltmp41:
	.size	__unnamed_3, .Ltmp41-__unnamed_3
	.cfi_endproc

	.globl	process
	.align	16, 0x90
	.type	process,@function
process:                                # @process
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp45:
	.cfi_def_cfa_offset 16
.Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp47:
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
.Ltmp48:
	.cfi_offset %rbx, -56
.Ltmp49:
	.cfi_offset %r12, -48
.Ltmp50:
	.cfi_offset %r13, -40
.Ltmp51:
	.cfi_offset %r14, -32
.Ltmp52:
	.cfi_offset %r15, -24
	movq	%rcx, %rbx
	movq	%rdi, %r14
	callq	Ecma_Object_create
	movq	%rax, %r13
	movq	(%rbx), %rdx
	movq	%r13, %rdi
	movl	$.L__unnamed_19, %esi
	callq	Ecma_setProperty
	movq	8(%rbx), %rdx
	movq	%r13, %rdi
	movl	$.L__unnamed_20, %esi
	callq	Ecma_setProperty
	movq	%r14, %rdi
	movl	$.L__unnamed_21, %esi
	callq	Ecma_getProperty
	movq	%rax, %r14
	movq	%r14, %rdi
	movl	$.L__unnamed_22, %esi
	callq	Ecma_getProperty
	movq	%rax, %rbx
	movq	%r13, %rdi
	movl	$.L__unnamed_23, %esi
	callq	Ecma_getProperty
	leaq	-48(%rbp), %r8
	movq	%rax, -48(%rbp)
	movq	%rbx, %rdi
	movq	%r13, %rsi
	movq	%r14, %rdx
	movl	$1, %ecx
	callq	Ecma_call
	movq	%r13, %rdi
	movl	$.L__unnamed_24, %esi
	callq	Ecma_getProperty
	movq	%rax, %rdi
	callq	Ecma_boolCast
	testb	$1, %al
	je	.LBB3_2
# BB#1:                                 # %then
	callq	Ecma_Object_create
	movq	%rax, %r14
	movq	%r13, %rdi
	movl	$.L__unnamed_25, %esi
	callq	Ecma_getProperty
	movq	%rax, %r12
	movq	%rsp, %rbx
	leaq	-16(%rbx), %r15
	movq	%r15, %rsp
	movq	%r13, %rdi
	movl	$.L__unnamed_26, %esi
	callq	Ecma_getProperty
	movq	%rax, -16(%rbx)
	callq	Ecma_Undefined_create
	movq	%r12, %rdi
	movq	%r14, %rsi
	movq	%rax, %rdx
	movl	$1, %ecx
	movq	%r15, %r8
	callq	Ecma_call
	movl	$1, %edi
	jmp	.LBB3_3
.LBB3_2:                                # %finally
	xorl	%edi, %edi
.LBB3_3:                                # %finally
	callq	Ecma_Boolean_create
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.Ltmp53:
	.size	process, .Ltmp53-process
	.cfi_endproc

	.globl	__unnamed_9
	.align	16, 0x90
	.type	__unnamed_9,@function
__unnamed_9:                            # @30
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%r15
.Ltmp59:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp60:
	.cfi_def_cfa_offset 24
	pushq	%r12
.Ltmp61:
	.cfi_def_cfa_offset 32
	pushq	%rbx
.Ltmp62:
	.cfi_def_cfa_offset 40
	pushq	%rax
.Ltmp63:
	.cfi_def_cfa_offset 48
.Ltmp64:
	.cfi_offset %rbx, -40
.Ltmp65:
	.cfi_offset %r12, -32
.Ltmp66:
	.cfi_offset %r14, -24
.Ltmp67:
	.cfi_offset %r15, -16
	movq	%rcx, %rbx
	movq	%rdi, %r14
	callq	Ecma_Object_create
	movq	%rax, %r12
	movq	(%rbx), %rdx
	movq	%r12, %rdi
	movl	$.L__unnamed_27, %esi
	callq	Ecma_setProperty
	movq	%r14, %rdi
	movl	$.L__unnamed_28, %esi
	callq	Ecma_getProperty
	movq	%rax, %r14
	movq	%r14, %rdi
	movl	$.L__unnamed_29, %esi
	callq	Ecma_getProperty
	movq	%rax, %r15
	movl	$.L__unnamed_30, %edi
	callq	Ecma_String_create
	movq	%rax, %rbx
	movq	%r12, %rdi
	movl	$.L__unnamed_31, %esi
	callq	Ecma_getProperty
	movq	%rbx, %rdi
	movq	%rax, %rsi
	callq	Ecma_Operator_Plus
	leaq	(%rsp), %r8
	movq	%rax, (%rsp)
	movq	%r15, %rdi
	movq	%r12, %rsi
	movq	%r14, %rdx
	movl	$1, %ecx
	callq	Ecma_call
	callq	Ecma_Undefined_create
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	ret
.Ltmp68:
	.size	__unnamed_9, .Ltmp68-__unnamed_9
	.cfi_endproc

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	 "stdio"
	.size	.L__unnamed_1, 6

	.type	.L__unnamed_11,@object  # @1
.L__unnamed_11:
	.asciz	 "data"
	.size	.L__unnamed_11, 5

	.type	.L__unnamed_12,@object  # @2
.L__unnamed_12:
	.asciz	 "stdio"
	.size	.L__unnamed_12, 6

	.type	.L__unnamed_13,@object  # @3
.L__unnamed_13:
	.asciz	 "write"
	.size	.L__unnamed_13, 6

	.type	.L__unnamed_14,@object  # @4
.L__unnamed_14:
	.asciz	 "data"
	.size	.L__unnamed_14, 5

	.type	.L__unnamed_2,@object   # @5
.L__unnamed_2:
	.asciz	 "print"
	.size	.L__unnamed_2, 6

	.type	.L__unnamed_15,@object  # @6
.L__unnamed_15:
	.asciz	 "msg"
	.size	.L__unnamed_15, 4

	.type	.L__unnamed_16,@object  # @7
.L__unnamed_16:
	.asciz	 "print"
	.size	.L__unnamed_16, 6

	.type	.L__unnamed_17,@object  # @8
.L__unnamed_17:
	.asciz	 "msg"
	.size	.L__unnamed_17, 4

	.type	.L__unnamed_18,@object  # @9
.L__unnamed_18:
	.asciz	 "\n"
	.size	.L__unnamed_18, 2

	.type	.L__unnamed_4,@object   # @10
.L__unnamed_4:
	.asciz	 "log"
	.size	.L__unnamed_4, 4

	.type	.L__unnamed_5,@object   # @11
.L__unnamed_5:
	.asciz	 "console"
	.size	.L__unnamed_5, 8

	.type	.L__unnamed_19,@object  # @12
.L__unnamed_19:
	.asciz	 "data"
	.size	.L__unnamed_19, 5

	.type	.L__unnamed_20,@object  # @13
.L__unnamed_20:
	.asciz	 "cb"
	.size	.L__unnamed_20, 3

	.type	.L__unnamed_21,@object  # @14
.L__unnamed_21:
	.asciz	 "console"
	.size	.L__unnamed_21, 8

	.type	.L__unnamed_22,@object  # @15
.L__unnamed_22:
	.asciz	 "log"
	.size	.L__unnamed_22, 4

	.type	.L__unnamed_23,@object  # @16
.L__unnamed_23:
	.asciz	 "data"
	.size	.L__unnamed_23, 5

	.type	.L__unnamed_24,@object  # @17
.L__unnamed_24:
	.asciz	 "cb"
	.size	.L__unnamed_24, 3

	.type	.L__unnamed_25,@object  # @18
.L__unnamed_25:
	.asciz	 "cb"
	.size	.L__unnamed_25, 3

	.type	.L__unnamed_26,@object  # @19
.L__unnamed_26:
	.asciz	 "data"
	.size	.L__unnamed_26, 5

	.type	.L__unnamed_6,@object   # @20
.L__unnamed_6:
	.asciz	 "process"
	.size	.L__unnamed_6, 8

	.type	.L__unnamed_7,@object   # @21
.L__unnamed_7:
	.asciz	 "process"
	.size	.L__unnamed_7, 8

	.type	.L__unnamed_8,@object   # @22
.L__unnamed_8:
	.asciz	 "Hello"
	.size	.L__unnamed_8, 6

	.type	.L__unnamed_27,@object  # @23
.L__unnamed_27:
	.asciz	 "data"
	.size	.L__unnamed_27, 5

	.type	.L__unnamed_28,@object  # @24
.L__unnamed_28:
	.asciz	 "console"
	.size	.L__unnamed_28, 8

	.type	.L__unnamed_29,@object  # @25
.L__unnamed_29:
	.asciz	 "log"
	.size	.L__unnamed_29, 4

	.type	.L__unnamed_30,@object  # @26
.L__unnamed_30:
	.asciz	 "Callback: "
	.size	.L__unnamed_30, 11

	.type	.L__unnamed_31,@object  # @27
.L__unnamed_31:
	.asciz	 "data"
	.size	.L__unnamed_31, 5

	.type	.L__unnamed_10,@object  # @28
.L__unnamed_10:
	.asciz	 "stdio"
	.size	.L__unnamed_10, 6


	.section	".note.GNU-stack","",@progbits
