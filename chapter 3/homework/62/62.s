	.file	"62.cpp"
	.text
	.globl	_Z7switch3PlS_6mode_t
	.def	_Z7switch3PlS_6mode_t;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7switch3PlS_6mode_t
_Z7switch3PlS_6mode_t:
.LFB0:
	.seh_endprologue
	cmpl	$4, %r8d
	ja	.L2
	movl	%r8d, %r8d
	leaq	.L4(%rip), %r9
	movslq	(%r9,%r8,4), %rax
	addq	%r9, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L4:
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L9-.L4
	.text
.L2:
	movl	$12, %eax
	jmp	.L1
.L8:
	movl	(%rdx), %eax
	movl	(%rcx), %ecx
	movl	%ecx, (%rdx)
	jmp	.L1
.L7:
	movl	(%rcx), %eax
	addl	(%rdx), %eax
	movl	%eax, (%rcx)
	jmp	.L1
.L6:
	movl	$59, (%rcx)
	movl	(%rdx), %eax
	jmp	.L1
.L5:
	movl	(%rdx), %eax
	movl	%eax, (%rcx)
	movl	$27, %eax
	jmp	.L1
.L9:
	movl	$27, %eax
.L1:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
