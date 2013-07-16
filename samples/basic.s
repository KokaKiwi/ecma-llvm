	.file	"/home/hervie_g/projects/ecma-llvm/samples/basic.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$104, %rsp
.Ltmp1:
	.cfi_def_cfa_offset 112
	callq	Ecma_Object_create
	leaq	Ecma_print, %rdi
	movq	%rax, 56(%rsp)          # 8-byte Spill
	callq	Ecma_Function_create
	leaq	__unnamed_1, %rsi
	movq	56(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	callq	Ecma_Object_create
	leaq	__unnamed_2, %rdi
	movq	%rax, 48(%rsp)          # 8-byte Spill
	callq	Ecma_Function_create
	leaq	__unnamed_3, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	leaq	__unnamed_4, %rdi
	callq	Ecma_Function_create
	leaq	__unnamed_5, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
	leaq	__unnamed_6, %rsi
	movq	56(%rsp), %rdi          # 8-byte Reload
	movq	48(%rsp), %rdx          # 8-byte Reload
	callq	Ecma_setProperty
	leaq	__unnamed_6, %rsi
	movq	56(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_5, %rsi
	movq	%rax, %rdi
	movq	%rax, 40(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	movl	$1, %edi
	movq	%rax, 32(%rsp)          # 8-byte Spill
	callq	Ecma_Integer_create
	movl	$2, %edi
	leaq	64(%rsp), %rsi
	movq	%rax, 64(%rsp)
	movq	%rsi, 24(%rsp)          # 8-byte Spill
	callq	Ecma_Integer_create
	movl	$3, %edi
	movq	%rax, 72(%rsp)
	callq	Ecma_Integer_create
	movl	$3, %edi
	movq	%rax, 80(%rsp)
	movq	24(%rsp), %rsi          # 8-byte Reload
	callq	Ecma_Array_create
	leaq	__unnamed_7, %rdi
	leaq	88(%rsp), %r8
	movq	%rax, 88(%rsp)
	movq	%r8, 16(%rsp)           # 8-byte Spill
	callq	Ecma_Function_create
	movl	$2, %ecx
	movq	%rax, 96(%rsp)
	movq	32(%rsp), %rdi          # 8-byte Reload
	movq	56(%rsp), %rsi          # 8-byte Reload
	movq	40(%rsp), %rdx          # 8-byte Reload
	movq	16(%rsp), %r8           # 8-byte Reload
	callq	Ecma_call
	movl	$0, %ecx
	movq	%rax, 8(%rsp)           # 8-byte Spill
	movl	%ecx, %eax
	addq	$104, %rsp
	ret
.Ltmp2:
	.size	main, .Ltmp2-main
	.cfi_endproc

	.align	16, 0x90
	.type	__unnamed_2,@function
__unnamed_2:                            # @11
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$72, %rsp
.Ltmp4:
	.cfi_def_cfa_offset 80
	movq	%rsi, 56(%rsp)          # 8-byte Spill
	movq	%rdi, 48(%rsp)          # 8-byte Spill
	movq	%rcx, 40(%rsp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_8, %rsi
	movq	40(%rsp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, 32(%rsp)          # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_1, %rsi
	movq	48(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_8, %rsi
	movq	32(%rsp), %rdi          # 8-byte Reload
	movq	%rax, 24(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_9, %rdi
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
.Ltmp5:
	.size	__unnamed_2, .Ltmp5-__unnamed_2
	.cfi_endproc

	.align	16, 0x90
	.type	__unnamed_4,@function
__unnamed_4:                            # @12
	.cfi_startproc
# BB#0:                                 # %bootstrap
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rcx, -8(%rbp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_10, %rsi
	movq	-8(%rbp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, -16(%rbp)         # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_11, %rsi
	movq	-8(%rbp), %rax          # 8-byte Reload
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rdi         # 8-byte Reload
	callq	Ecma_setProperty
	movl	$0, %edi
	callq	Ecma_Integer_create
	leaq	__unnamed_12, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	movq	%rax, %rdx
	callq	Ecma_setProperty
.LBB2_1:                                # %test
                                        # =>This Inner Loop Header: Depth=1
	leaq	__unnamed_12, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_10, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -24(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_13, %rsi
	movq	%rax, %rdi
	callq	Ecma_getProperty
	movq	-24(%rbp), %rdi         # 8-byte Reload
	movq	%rax, %rsi
	callq	Ecma_Operator_Lesser
	movq	%rax, %rdi
	callq	Ecma_boolCast
	testb	$1, %al
	jne	.LBB2_2
	jmp	.LBB2_3
.LBB2_2:                                # %then
                                        #   in Loop: Header=BB2_1 Depth=1
	leaq	__unnamed_10, %rsi
	movq	%rsi, -32(%rbp)         # 8-byte Spill
	callq	Ecma_Object_create
	movl	$__unnamed_11, %esi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -40(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movq	%rsp, %rsi
	addq	$-16, %rsi
	movq	%rsi, %rsp
	movq	-40(%rbp), %rdi         # 8-byte Reload
	movq	-16(%rbp), %rcx         # 8-byte Reload
	movq	%rdi, -48(%rbp)         # 8-byte Spill
	movq	%rcx, %rdi
	movq	-32(%rbp), %rdx         # 8-byte Reload
	movq	%rsi, -56(%rbp)         # 8-byte Spill
	movq	%rdx, %rsi
	movq	%rax, -64(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_12, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	movq	%rax, -72(%rbp)         # 8-byte Spill
	callq	Ecma_getProperty
	movq	-72(%rbp), %rdi         # 8-byte Reload
	movq	%rax, %rsi
	callq	Ecma_getIndex
	movq	-56(%rbp), %rcx         # 8-byte Reload
	movq	%rax, (%rcx)
	callq	Ecma_Undefined_create
	movl	$1, %ecx
	movq	-64(%rbp), %rdi         # 8-byte Reload
	movq	-48(%rbp), %rsi         # 8-byte Reload
	movq	%rax, %rdx
	movq	-56(%rbp), %r8          # 8-byte Reload
	callq	Ecma_call
	movq	%rax, -80(%rbp)         # 8-byte Spill
	jmp	.LBB2_1
.LBB2_3:                                # %finally
	callq	Ecma_Undefined_create
	movq	%rbp, %rsp
	popq	%rbp
	ret
.Ltmp11:
	.size	__unnamed_4, .Ltmp11-__unnamed_4
	.cfi_endproc

	.align	16, 0x90
	.type	__unnamed_7,@function
__unnamed_7:                            # @13
	.cfi_startproc
# BB#0:                                 # %bootstrap
	subq	$56, %rsp
.Ltmp13:
	.cfi_def_cfa_offset 64
	movq	%rdi, 40(%rsp)          # 8-byte Spill
	movq	%rcx, 32(%rsp)          # 8-byte Spill
	callq	Ecma_Object_create
	leaq	__unnamed_14, %rsi
	movq	32(%rsp), %rcx          # 8-byte Reload
	movq	(%rcx), %rdx
	movq	%rax, %rdi
	movq	%rax, 24(%rsp)          # 8-byte Spill
	callq	Ecma_setProperty
	leaq	__unnamed_6, %rsi
	movq	40(%rsp), %rdi          # 8-byte Reload
	callq	Ecma_getProperty
	leaq	__unnamed_3, %rsi
	movq	%rax, %rdi
	movq	%rax, 16(%rsp)          # 8-byte Spill
	callq	Ecma_getProperty
	leaq	__unnamed_14, %rsi
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
.Ltmp14:
	.size	__unnamed_7, .Ltmp14-__unnamed_7
	.cfi_endproc

	.type	__unnamed_1,@object     # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
__unnamed_1:
	.asciz	 "print"
	.size	__unnamed_1, 6

	.type	__unnamed_8,@object     # @1
__unnamed_8:
	.asciz	 "msg"
	.size	__unnamed_8, 4

	.type	__unnamed_9,@object     # @2
__unnamed_9:
	.asciz	 "\n"
	.size	__unnamed_9, 2

	.type	__unnamed_13,@object    # @3
__unnamed_13:
	.asciz	 "length"
	.size	__unnamed_13, 7

	.type	__unnamed_11,@object    # @4
__unnamed_11:
	.asciz	 "cb"
	.size	__unnamed_11, 3

	.type	__unnamed_10,@object    # @5
__unnamed_10:
	.asciz	 "data"
	.size	__unnamed_10, 5

	.type	__unnamed_12,@object    # @6
__unnamed_12:
	.asciz	 "i"
	.size	__unnamed_12, 2

	.type	__unnamed_5,@object     # @7
__unnamed_5:
	.asciz	 "fn"
	.size	__unnamed_5, 3

	.type	__unnamed_6,@object     # @8
__unnamed_6:
	.asciz	 "console"
	.size	__unnamed_6, 8

	.type	__unnamed_3,@object     # @9
__unnamed_3:
	.asciz	 "log"
	.size	__unnamed_3, 4

	.type	__unnamed_14,@object    # @10
__unnamed_14:
	.asciz	 "item"
	.size	__unnamed_14, 5


	.section	".note.GNU-stack","",@progbits
