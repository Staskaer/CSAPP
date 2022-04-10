	.file	"64.cpp"
	.text
	.globl	_Z9store_elelllPl
	.def	_Z9store_elelllPl;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9store_elelllPl
_Z9store_elelllPl:
.LFB0:
	.seh_endprologue
	movl	2132+A(%rip), %eax
	movl	%eax, (%r9)
	movl	$1820, %eax
	ret
	.seh_endproc
	.globl	A
	.bss
	.align 32
A:
	.space 1820
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
