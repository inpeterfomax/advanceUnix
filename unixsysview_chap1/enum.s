	.file	"enum.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
	.string	"for test br functin "
.LC2:
	.string	"keep add on test-br 1 "
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -4(%rbp)
	movl	$.LC0, %eax
	movl	-4(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$.LC1, %edi
	call	puts
	movl	$.LC2, %edi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.3-12ubuntu2) 4.5.3"
	.section	.note.GNU-stack,"",@progbits
