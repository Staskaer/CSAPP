/*

find_range:
	vxorps %xmm1, %xmm1, %xmm1
	vucomiss %xmm0, %xmm1
	cmova $0, %eax
	cmove $1, %eax
	cmovb $2, %eax
	cmovp $3, %eax
	rep;ret

*/