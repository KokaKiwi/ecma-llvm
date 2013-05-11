	.file	"../tests/basic.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	subq	$88, %rsp
.Ltmp1:
	.cfi_def_cfa_offset 96
	movl	$swap, %edi
	callq	Ecma_Function_create
	movq	%rax, 80(%rsp)
	movl	$index, %edi
	callq	Ecma_Function_create
	movq	%rax, 72(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 8(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 16(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 24(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 32(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 40(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 48(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rax, 56(%rsp)
	movl	$.L__unnamed_1, %edi
	callq	Ecma_String_create
	leaq	8(%rsp), %rsi
	movq	%rax, 64(%rsp)
	movl	$8, %edi
	callq	Ecma_Array_create
	movq	%rax, (%rsp)
	xorl	%eax, %eax
	addq	$88, %rsp
	ret
.Ltmp2:
	.size	main, .Ltmp2-main
	.cfi_endproc

	.globl	swap
	.align	16, 0x90
	.type	swap,@function
swap:                                   # @swap
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%r14
.Ltmp6:
	.cfi_def_cfa_offset 16
	pushq	%rbx
.Ltmp7:
	.cfi_def_cfa_offset 24
	subq	$24, %rsp
.Ltmp8:
	.cfi_def_cfa_offset 48
.Ltmp9:
	.cfi_offset %rbx, -24
.Ltmp10:
	.cfi_offset %r14, -16
	movq	(%rsi), %rbx
	movq	%rbx, 16(%rsp)
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rbx, %rdi
	movq	%rax, %rsi
	callq	Ecma_getIndex
	movq	%rax, 8(%rsp)
	movq	16(%rsp), %rbx
	movl	$1, %edi
	callq	Ecma_Integer_create
	movq	%rbx, %rdi
	movq	%rax, %rsi
	callq	Ecma_getIndex
	movq	%rax, %r14
	movq	16(%rsp), %rbx
	xorl	%edi, %edi
	callq	Ecma_Integer_create
	movq	%rbx, %rdi
	movq	%rax, %rsi
	movq	%r14, %rdx
	callq	Ecma_setIndex
	movq	16(%rsp), %rbx
	movq	8(%rsp), %r14
	movl	$1, %edi
	callq	Ecma_Integer_create
	movq	%rbx, %rdi
	movq	%rax, %rsi
	movq	%r14, %rdx
	callq	Ecma_setIndex
	callq	Ecma_Undefined_create
	addq	$24, %rsp
	popq	%rbx
	popq	%r14
	ret
.Ltmp11:
	.size	swap, .Ltmp11-swap
	.cfi_endproc

	.globl	index
	.align	16, 0x90
	.type	index,@function
index:                                  # @index
	.cfi_startproc
# BB#0:                                 # %bootstrap
	pushq	%rax
.Ltmp13:
	.cfi_def_cfa_offset 16
	movl	$2, %edi
	callq	Ecma_Integer_create
	popq	%rdx
	ret
.Ltmp14:
	.size	index, .Ltmp14-index
	.cfi_endproc

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	 "Hello world!"
	.size	.L__unnamed_1, 13


	.section	".note.GNU-stack","",@progbits
