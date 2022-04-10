	.file	"70.cpp"
	.text
	.globl	_Z4procP3ele
	.def	_Z4procP3ele;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4procP3ele
_Z4procP3ele:
.LFB0:
	.seh_endprologue
	movq	8(%rcx), %rdx
	movq	(%rdx), %rax
	movl	(%rax), %eax
	subl	8(%rdx), %eax
	movl	%eax, (%rcx)
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
