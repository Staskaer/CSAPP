	.file	"66.cpp"
	.text
	.globl	_Z7sum_collPPll
	.def	_Z7sum_collPPll;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7sum_collPPll
_Z7sum_collPPll:
.LFB0:
	.seh_endprologue
	movl	$0, %eax
	movl	$0, %r9d
.L3:
	leal	(%rcx,%rcx,2), %r10d
	cmpl	%r9d, %r10d
	jle	.L1
	movslq	%r9d, %r10
	movq	(%rdx,%r10,8), %r10
	movslq	%r8d, %r11
	addl	(%r10,%r11,4), %eax
	addl	$1, %r9d
	jmp	.L3
.L1:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
