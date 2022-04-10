	.file	"68.cpp"
	.text
	.globl	_Z6getValP4str1P4str2
	.def	_Z6getValP4str1P4str2;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6getValP4str1P4str2
_Z6getValP4str1P4str2:
.LFB0:
	.seh_endprologue
	movslq	8(%rdx), %rax
	addq	32(%rdx), %rax
	movq	%rax, 184(%rcx)
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
