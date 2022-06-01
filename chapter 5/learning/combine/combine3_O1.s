	.file	"combine3.cpp"
	.text
	.globl	_Z10vec_get_daP7vec_rec
	.def	_Z10vec_get_daP7vec_rec;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10vec_get_daP7vec_rec
_Z10vec_get_daP7vec_rec:
.LFB0:
	.seh_endprologue
	movq	8(%rcx), %rax
	ret
	.seh_endproc
	.globl	_Z11vec_get_lenP7vec_rec
	.def	_Z11vec_get_lenP7vec_rec;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11vec_get_lenP7vec_rec
_Z11vec_get_lenP7vec_rec:
.LFB1:
	.seh_endprologue
	movl	(%rcx), %eax
	ret
	.seh_endproc
	.globl	_Z8combine3P7vec_recPi
	.def	_Z8combine3P7vec_recPi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8combine3P7vec_recPi
_Z8combine3P7vec_recPi:
.LFB2:
	.seh_endprologue
	movl	(%rcx), %r8d
	movl	$1, (%rdx)
	movq	8(%rcx), %rcx
	testl	%r8d, %r8d
	jle	.L3
	movq	%rcx, %rax
	leal	-1(%r8), %r8d
	leaq	4(%rcx,%r8,4), %r8
.L5:
	movl	(%rdx), %ecx
	imull	(%rax), %ecx
	movl	%ecx, (%rdx)
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L5
.L3:
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
