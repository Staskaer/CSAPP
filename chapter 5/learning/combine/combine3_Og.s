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
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rdi
	movq	%rdx, %rbx
	call	_Z11vec_get_lenP7vec_rec
	movl	%eax, %esi
	movl	$1, (%rbx)
	movq	%rdi, %rcx
	call	_Z10vec_get_daP7vec_rec
	movl	$0, %edx
.L5:
	cmpl	%esi, %edx
	jge	.L3
	movslq	%edx, %rcx
	movl	(%rax,%rcx,4), %ecx
	imull	(%rbx), %ecx
	movl	%ecx, (%rbx)
	addl	$1, %edx
	jmp	.L5
.L3:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
