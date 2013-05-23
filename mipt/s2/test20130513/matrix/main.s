	.file	"main.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	f
	.type	f, @function
f:
.LFB11:
	.cfi_startproc
	mov	eax, DWORD PTR [esp+4]
	fld1
	fdiv	DWORD PTR [eax]
	mov	eax, DWORD PTR [esp+8]
	fstp	QWORD PTR [eax]
	ret
	.cfi_endproc
.LFE11:
	.size	f, .-f
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
