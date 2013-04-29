	.file	"1.3.c"
	.text
	.p2align 4,,15
	.globl	sum_element
	.type	sum_element, @function
sum_element:
.LFB11:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	leal	0(,%eax,8), %edx
	subl	%eax, %edx
	addl	%ecx, %edx
	leal	(%eax,%eax,4), %eax
	addl	%eax, %ecx
	movl	mat1(,%edx,4), %eax
	addl	mat2(,%ecx,4), %eax
	ret
	.cfi_endproc
.LFE11:
	.size	sum_element, .-sum_element
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	rep
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.comm	mat2,140,32
	.comm	mat1,140,32
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
