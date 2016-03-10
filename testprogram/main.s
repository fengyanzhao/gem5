	.cpu arm10tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"main.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%d\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	mov	r3, #7
	str	r3, [fp, #-8]
	mov	r3, #8
	str	r3, [fp, #-12]
	ldr	r0, [fp, #-12]
	ldr	r1, [fp, #-8]
	comp_enter
	comp_leave
	rct r3,r3
	str	r0, [fp, #-16]
	ldr	r0, .L2
	ldr	r1, [fp, #-16]
	bl	printf
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.1"
	.section	.note.GNU-stack,"",%progbits
