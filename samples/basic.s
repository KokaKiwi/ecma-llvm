	.file	"../samples/basic.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$72, %rsp
.Ltmp1:
	.cfi_def_cfa_offset 80
	callq	Ecma_Object_create
	movq	%rax, 48(%rsp)          # 8-byte Spill
	callq	Ecma_Null_create
	leaq	__unnamed_1, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	leaq	print, %rdi
	callq	Ecma_Function_create
	leaq	__unnamed_2, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	callq	Ecma_Object_create
	leaq	__unnamed_3, %rdi
	movq	%rax, 40(%rsp)          # 8-byte Spill
	callq	Ecma_Function_create
	leaq	__unnamed_4, %rsi
	movq	40(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	leaq	__unnamed_5, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	40(%rsp), %rdx          # 8-byte Reload
	callq	Ecma_setProperty
	leaq	process, %rdi
	callq	Ecma_Function_create
	leaq	__unnamed_6, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	leaq	__unnamed_6, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_7, %rdi
	movq	%rax, 32(%rsp)          # 8-byte Spill
	callq	Ecma_String_create
	leaq	__unnamed_8, %rdi
	leaq	56(%rsp), %r8
	movq	%rax, 56(%rsp)
	movq	%r8, 24(%rsp)           # 8-byte Spill
	callq	Ecma_Function_create
	movq	%rax, 64(%rsp)
	callq	Ecma_Undefined_create
	movl	$2, %ecx
	movq	32(%rsp), %rdi          # 8-byte Reload
	movq	48(%rsp), %rsi          # 8-byte Reload
	movq	%rax, %rdx
	movq	24(%rsp), %r8           # 8-byte Reload
	callq	Ecma_call
	movl	$20, %edi
	movq	%rax, 16(%rsp)          # 8-byte Spill
	callq	Ecma_Integer_create
	leaq	__unnamed_1, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, 8(%rsp)           # 8-byte Spill
	callq	Ecma_getProperty
	movl	$10, %edi
	movq	%rax, (%rsp)            # 8-byte Spill
	callq	Ecma_Integer_create
	movq	(%rsp), %rdi            # 8-byte Reload
	movq	%rax, %rsi
	movq	8(%rsp), %rdx           # 8-byte Reload
	callq	Ecma_setIndex
	movl	$0, %eax
	addq	$72, %rsp
	ret
.Ltmp2:
	.size	main, .Ltmp2-main
	.cfi_endproc

	.globl	print
	.align	16, 0x90
	.type	print,@function
print:                                  # @print
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$56, %rsp
.Ltmp4:
	.cfi_def_cfa_offset 64
	movq	%rdi, 40(%rsp)          # 8-byte Spill
	movq	%rcx, 32(%rsp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_9, %rsi
	movq	32(%rsp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)          # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_1, %rsi
	movq	40(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_10, %rsi
	movq	%rax, %rdi
	movq	%rax, 16(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_9, %rsi
	movq	24(%rsp), %rdi          # 8-byte Reload
	movq	%rax, 8(%rsp)           # 8-byte Spill
	callq	Ecma_getProperty
	movl	$1, %ecx
	leaq	48(%rsp), %r8
	movq	%rax, 48(%rsp)
	movq	8(%rsp), %rdi           # 8-byte Reload
	movq	24(%rsp), %rsi          # 8-byte Reload
	movq	16(%rsp), %rdx          # 8-byte Reload
	callq	Ecma_call
	movq	%rax, (%rsp)            # 8-byte Spill
	callq	Ecma_Undefined_create
	addq	$56, %rsp
	ret
.Ltmp5:
	.size	print, .Ltmp5-print
	.cfi_endproc

	.align	16, 0x90
	.type	__unnamed_3,@function
__unnamed_3:                            # @12
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$72, %rsp
.Ltmp7:
	.cfi_def_cfa_offset 80
	movq	%rsi, 56(%rsp)          # 8-byte Spill
	movq	%rdi, 48(%rsp)          # 8-byte Spill
	movq	%rcx, 40(%rsp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_11, %rsi
	movq	40(%rsp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, 32(%rsp)          # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_2, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_11, %rsi
	movq	32(%rsp), %rdi          # 8-byte Reload
	movq	%rax, 24(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_12, %rdi
	movq	%rax, 16(%rsp)          # 8-byte Spill
	callq	Ecma_String_create
	movq	16(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rsi
	callq	Ecma_Operator_Plus
	movl	$1, %ecx
	leaq	64(%rsp), %r8
	movq	%rax, 64(%rsp)
	movq	24(%rsp), %rdi          # 8-byte Reload
	movq	32(%rsp), %rsi          # 8-byte Reload
	movq	56(%rsp), %rdx          # 8-byte Reload
	callq	Ecma_call
	movq	%rax, 8(%rsp)           # 8-byte Spill
	callq	Ecma_Undefined_create
	addq	$72, %rsp
	ret
.Ltmp8:
	.size	__unnamed_3, .Ltmp8-__unnamed_3
	.cfi_endproc

	.globl	process
	.align	16, 0x90
	.type	process,@function
process:                                # @process
	.cfi_startproc
# BB#0:                                 # %bootstrap
	pushq	%rbp
.Ltmp11:
	.cfi_def_cfa_offset 16
.Ltmp12:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp13:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	%rdi, -16(%rbp)         # 8-byte Spill
	movq	%rcx, -24(%rbp)         # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_9, %rsi
	movq	-24(%rbp), %rcx         # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, -32(%rbp)         # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_13, %rsi
	movq	-24(%rbp), %rax         # 8-byte Reload
	movq	8(%rax), %rdx
	movq	-32(%rbp), %rdi         # 8-byte Reload
	callq	Ecma_setProperty
	leaq	__unnamed_5, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_4, %rsi
	movq	%rax, %rdi
	movq	%rax, -40(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_9, %rsi
	movq	-32(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -48(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movl	$1, %ecx
	leaq	-8(%rbp), %r8
	movq	%rax, -8(%rbp)
	movq	-48(%rbp), %rdi         # 8-byte Reload
	movq	-32(%rbp), %rsi         # 8-byte Reload
	movq	-40(%rbp), %rdx         # 8-byte Reload
	callq	Ecma_call
	leaq	__unnamed_13, %rsi
	movq	-32(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -56(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movq	%rax, %rdi
	callq	Ecma_boolCast
	testb	$1, %al
	jne	.LBB3_1
	jmp	.LBB3_2
.LBB3_1:                                # %then
	leaq	__unnamed_9, %rsi
	movq	%rsi, -64(%rbp)         # 8-byte Spill
	callq	Ecma_Object_create
	movl	$__unnamed_13, %esi
	movq	-32(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -72(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movq	%rsp, %rsi
	addq	$-16, %rsi
	movq	%rsi, %rsp
	movq	-72(%rbp), %rdi         # 8-byte Reload
	movq	-32(%rbp), %rcx         # 8-byte Reload
	movq	%rdi, -80(%rbp)         # 8-byte Spill
	movq	%rcx, %rdi
	movq	-64(%rbp), %rdx         # 8-byte Reload
	movq	%rsi, -88(%rbp)         # 8-byte Spill
	movq	%rdx, %rsi
	movq	%rax, -96(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movq	-88(%rbp), %rcx         # 8-byte Reload
	movq	%rax, (%rcx)
	callq	Ecma_Undefined_create
	movl	$1, %ecx
	movq	-96(%rbp), %rdi         # 8-byte Reload
	movq	-80(%rbp), %rsi         # 8-byte Reload
	movq	%rax, %rdx
	movq	-88(%rbp), %r8          # 8-byte Reload
	callq	Ecma_call
	movl	$1, %edi
	movq	%rax, -104(%rbp)        # 8-byte Spill
	callq	Ecma_Boolean_create
	movq	%rax, -112(%rbp)        # 8-byte Spill
	jmp	.LBB3_3
.LBB3_2:                                # %finally
	movl	$0, %edi
	callq	Ecma_Boolean_create
	movq	%rax, -112(%rbp)        # 8-byte Spill
.LBB3_3:                                # %UnifiedReturnBlock
	movq	-112(%rbp), %rax        # 8-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	ret
.Ltmp14:
	.size	process, .Ltmp14-process
	.cfi_endproc

	.align	16, 0x90
	.type	__unnamed_8,@function
__unnamed_8:                            # @13
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$72, %rsp
.Ltmp16:
	.cfi_def_cfa_offset 80
	movq	%rdi, 56(%rsp)          # 8-byte Spill
	movq	%rcx, 48(%rsp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_9, %rsi
	movq	48(%rsp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, 40(%rsp)          # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_5, %rsi
	movq	56(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_4, %rsi
	movq	%rax, %rdi
	movq	%rax, 32(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_14, %rdi
	movq	%rax, 24(%rsp)          # 8-byte Spill
	callq	Ecma_String_create
	leaq	__unnamed_9, %rsi
	movq	40(%rsp), %rdi          # 8-byte Reload
	movq	%rax, 16(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	movq	16(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rsi
	callq	Ecma_Operator_Plus
	movl	$1, %ecx
	leaq	64(%rsp), %r8
	movq	%rax, 64(%rsp)
	movq	24(%rsp), %rdi          # 8-byte Reload
	movq	40(%rsp), %rsi          # 8-byte Reload
	movq	32(%rsp), %rdx          # 8-byte Reload
	callq	Ecma_call
	movq	%rax, 8(%rsp)           # 8-byte Spill
	callq	Ecma_Undefined_create
	addq	$72, %rsp
	ret
.Ltmp17:
	.size	__unnamed_8, .Ltmp17-__unnamed_8
	.cfi_endproc

	.type	__unnamed_10,@object    # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
__unnamed_10:
	.asciz	 "write"
	.size	__unnamed_10, 6

	.type	__unnamed_2,@object     # @1
__unnamed_2:
	.asciz	 "print"
	.size	__unnamed_2, 6

	.type	__unnamed_11,@object    # @2
__unnamed_11:
	.asciz	 "msg"
	.size	__unnamed_11, 4

	.type	__unnamed_12,@object    # @3
__unnamed_12:
	.asciz	 "\n"
	.size	__unnamed_12, 2

	.type	__unnamed_13,@object    # @4
__unnamed_13:
	.asciz	 "cb"
	.size	__unnamed_13, 3

	.type	__unnamed_6,@object     # @5
__unnamed_6:
	.asciz	 "process"
	.size	__unnamed_6, 8

	.type	__unnamed_7,@object     # @6
__unnamed_7:
	.asciz	 "Hello"
	.size	__unnamed_7, 6

	.type	__unnamed_5,@object     # @7
__unnamed_5:
	.asciz	 "console"
	.size	__unnamed_5, 8

	.type	__unnamed_4,@object     # @8
__unnamed_4:
	.asciz	 "log"
	.size	__unnamed_4, 4

	.type	__unnamed_14,@object    # @9
__unnamed_14:
	.asciz	 "Callback: "
	.size	__unnamed_14, 11

	.type	__unnamed_9,@object     # @10
__unnamed_9:
	.asciz	 "data"
	.size	__unnamed_9, 5

	.type	__unnamed_1,@object     # @11
__unnamed_1:
	.asciz	 "stdio"
	.size	__unnamed_1, 6


	.section	".note.GNU-stack","",@progbits
