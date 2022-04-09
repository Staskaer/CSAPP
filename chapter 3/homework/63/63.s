	.file	"63.cpp"
	.text
	.p2align 4,,15
	.globl	_Z11switch_probll
	.def	_Z11switch_probll;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11switch_probll
_Z11switch_probll:
.LFB0:
	.seh_endprologue
	subl	$60, %edx
	cmpl	$5, %edx
	ja	.L2
	leaq	.L4(%rip), %r8
	movslq	(%r8,%rdx,4), %rax
	addq	%r8, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
	.p2align 4,,10
.L5:
	movl	%ecx, %eax
	sall	$4, %eax
	subl	%ecx, %eax
	movl	%eax, %ecx
.L3:
	imull	%ecx, %ecx
.L2:
	leal	75(%rcx), %eax
	ret
	.p2align 4,,10
.L6:
	movl	%ecx, %eax
	sarl	$3, %eax
	ret
	.p2align 4,,10
.L7:
	leal	0(,%rcx,8), %eax
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
