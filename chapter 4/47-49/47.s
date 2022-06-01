	.file	"47.c"
	.text
	.globl	bubble_b
	.def	bubble_b;	.scl	2;	.type	32;	.endef
	.seh_proc	bubble_b
bubble_b:
	.seh_endprologue
	leal	-1(%rdx), %r11d
	jmp	.L2
.L4:
	addq	$4, %rax
	addq	$4, %rdx
	addl	$1, %r8d
.L3:
	cmpl	%r11d, %r8d
	jge	.L7
	movl	(%rdx), %r9d
	movl	(%rax), %r10d
	cmpl	%r10d, %r9d
	jge	.L4
	movl	%r10d, (%rdx)
	movl	%r9d, (%rax)
	jmp	.L4
.L7:
	subl	$1, %r11d
.L2:
	testl	%r11d, %r11d
	jle	.L8
	leaq	4(%rcx), %rdx
	movq	%rcx, %rax
	movl	$0, %r8d
	jmp	.L3
.L8:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
