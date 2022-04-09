	.file	"61.cpp"
	.text
	.p2align 4,,15
	.globl	_Z9cread_altPl
	.def	_Z9cread_altPl;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9cread_altPl
_Z9cread_altPl:
.LFB0:
	.seh_endprologue
	xorl	%eax, %eax
	testq	%rcx, %rcx
	je	.L1
	movl	(%rcx), %eax
.L1:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
