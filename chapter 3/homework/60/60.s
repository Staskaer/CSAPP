	.file	"61.cpp"
	.text
	.globl	_Z4loopli
	.def	_Z4loopli;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4loopli
_Z4loopli:
.LFB0:
	.seh_endprologue
	movl	%ecx, %r10d
	movl	$1, %r9d
	movl	$0, %eax
.L3:
	testl	%r9d, %r9d
	je	.L1
	movl	%r9d, %ecx
	orl	%r10d, %ecx
	orl	%ecx, %eax
	movl	%edx, %r8d
	sarl	$31, %r8d
	shrl	$24, %r8d
	leal	(%rdx,%r8), %ecx
	movzbl	%cl, %ecx
	subl	%r8d, %ecx
	sall	%cl, %r9d
	jmp	.L3
.L1:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
