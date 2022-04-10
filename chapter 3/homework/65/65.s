	.file	"65.cpp"
	.text
	.globl	_Z9transpodePA15_l
	.def	_Z9transpodePA15_l;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9transpodePA15_l
_Z9transpodePA15_l:
.LFB0:
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	60(%rcx), %rbx
	leaq	4(%rcx), %r11
	leaq	64(%rcx), %r9
	movl	$0, %r10d
	jmp	.L2
.L3:
	addq	$60, %rbx
	addq	$4, %r11
	addq	$64, %r9
.L2:
	addl	$1, %r10d
	cmpl	$15, %r10d
	je	.L7
	testl	%r10d, %r10d
	jle	.L3
	movq	%r11, %rdx
	movq	%rbx, %rax
.L4:
	movl	(%rax), %ecx
	movl	(%rdx), %r8d
	movl	%r8d, (%rax)
	movl	%ecx, (%rdx)
	addq	$4, %rax
	addq	$60, %rdx
	cmpq	%r9, %rax
	jne	.L4
	jmp	.L3
.L7:
	popq	%rbx
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
