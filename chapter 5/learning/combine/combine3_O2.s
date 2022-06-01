	.file	"combine3.cpp"
	.text
	.p2align 4,,15
	.globl	_Z10vec_get_daP7vec_rec
	.def	_Z10vec_get_daP7vec_rec;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10vec_get_daP7vec_rec
_Z10vec_get_daP7vec_rec:
.LFB0:
	.seh_endprologue
	movq	8(%rcx), %rax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z11vec_get_lenP7vec_rec
	.def	_Z11vec_get_lenP7vec_rec;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11vec_get_lenP7vec_rec
_Z11vec_get_lenP7vec_rec:
.LFB1:
	.seh_endprologue
	movl	(%rcx), %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z8combine3P7vec_recPi
	.def	_Z8combine3P7vec_recPi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8combine3P7vec_recPi
_Z8combine3P7vec_recPi:
.LFB2:
	.seh_endprologue
	movl	(%rcx), %r8d
	movq	8(%rcx), %rax
	testl	%r8d, %r8d
	movl	$1, (%rdx)
	jle	.L4
	leal	-1(%r8), %ecx
	leaq	4(%rax,%rcx,4), %r8
	movl	$1, %ecx
	.p2align 4,,10
.L7:
	imull	(%rax), %ecx
	addq	$4, %rax
	cmpq	%rax, %r8
	movl	%ecx, (%rdx)
	jne	.L7
.L4:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
