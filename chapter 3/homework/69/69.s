	.file	"69.cpp"
	.text
	.globl	_Z4testlP8b_struct
	.def	_Z4testlP8b_struct;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4testlP8b_struct
_Z4testlP8b_struct:
.LFB0:
	.seh_endprologue
	movl	144(%rdx), %r8d
	addl	(%rdx), %r8d
	movslq	%ecx, %rcx
	leaq	0(,%rcx,4), %rax
	leaq	(%rax,%rcx), %r10
	leaq	0(,%r10,4), %r9
	movslq	4(%rdx,%r9), %r9
	addq	%rcx, %rax
	addq	%r9, %rax
	movl	%r8d, 8(%rdx,%rax,4)
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
