	.file	"1_out.c"
	.section	.rodata
.LC0:
	.string	"Entering main"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$.LC0, %edi
	call	puts
	movl	$40, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$20, %rax
	movq	-8(%rbp), %rdx
	addq	$8, %rdx
	movl	(%rdx), %edx
	addl	$10, %edx
	movl	%edx, (%rax)
	movl	$30, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	$40, %eax
	movl	%eax, -12(%rbp)
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
