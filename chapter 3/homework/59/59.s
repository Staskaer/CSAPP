	.file	"59.cpp"
	.text
	.globl	_Z10store_prodPnxx
	.def	_Z10store_prodPnxx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10store_prodPnxx
_Z10store_prodPnxx:
.LFB1:
	.seh_endprologue
	movq	%r8, %r9
	sarq	$63, %r9
	movq	%rdx, %r10
	sarq	$63, %r10
	imulq	%r8, %r10
	imulq	%rdx, %r9
	addq	%r10, %r9
	movq	%rdx, %rax
	mulq	%r8
	addq	%r9, %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
