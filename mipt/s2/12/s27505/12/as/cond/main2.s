	.syntax unified
	.arch armv7-a
	.eabi_attribute 27, 3
	.fpu vfpv3-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.thumb
	.file	"main.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%d\000"
	.global	__aeabi_idiv
	.text
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #16
	add	r7, sp, #0
	movw	r3, #:lower16:.LC0
	movt	r3, #:upper16:.LC0
	add	r2, r7, #12
	mov	r0, r3
	mov	r1, r2
	bl	__isoc99_scanf
	movw	r3, #:lower16:.LC0
	movt	r3, #:upper16:.LC0
	add	r2, r7, #8
	mov	r0, r3
	mov	r1, r2
	bl	__isoc99_scanf
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #8]
	mov	r0, r2
	mov	r1, r3
	bl	__aeabi_idiv
	mov	r3, r0
	str	r3, [r7, #4]
	movw	r3, #:lower16:.LC0
	movt	r3, #:upper16:.LC0
	mov	r0, r3
	ldr	r1, [r7, #4]
	addpl	r1, r1, r1
	bl	printf
	mov	r3, #0
	mov	r0, r3
	add	r7, r7, #16
	mov	sp, r7
	pop	{r7, pc}
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",%progbits
