	.file	"58.cpp"
	.text
	.globl	_Z7decode2lll
	.def	_Z7decode2lll;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7decode2lll
_Z7decode2lll:
.LFB30:
	.seh_endprologue
	subl	%r8d, %edx
	imull	%edx, %ecx
	movl	%ecx, %r9d
	movl	%edx, %eax
	movl	$63, %ecx
	sall	%cl, %eax
	sarl	%cl, %eax
	xorl	%r9d, %eax
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
