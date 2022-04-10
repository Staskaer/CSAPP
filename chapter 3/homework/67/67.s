	.file	"67.cpp"
	.text
	.p2align 4,,15
	.globl	_Z7process4strA
	.def	_Z7process4strA;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7process4strA
_Z7process4strA:
.LFB0:
	.seh_endprologue
	movq	%rcx, %rax
	movq	(%rdx), %rcx
	movq	8(%rdx), %rdx
	movq	%rcx, %r8
	movl	%ecx, 4(%rax)
	movl	(%rdx), %edx
	sarq	$32, %r8
	movl	%r8d, (%rax)
	movl	%edx, 8(%rax)
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z4evallll
	.def	_Z4evallll;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4evallll
_Z4evallll:
.LFB1:
	.seh_endprologue
	addl	%edx, %ecx
	leal	(%rcx,%r8), %eax
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
