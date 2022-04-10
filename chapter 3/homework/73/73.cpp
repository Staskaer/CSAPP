/*
find_range:
	vxorps %xmm1, %xmm1, %xmm1
	vucomiss %xmm0, %xmm1
	ja .L5
	jp .L8
	movl $1, %eax
	je .L3
	.L8:
	seta %al
	movzbl %al, %eax
	addl $2, %eax
	ret
	.L5:
	movl $0, %eax
	.L3:
	rep;ret

*/