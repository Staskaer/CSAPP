void bubble_b(long *data, long count)
{
    long i, last;
    long *p0; //data[i]
    long *p1; //data[i+1]

    for (last = count - 1; last > 0; last--)
    {
        p0 = data;
        p1 = data + 1;
        for (i = 0; i < last; i++)
        {
            if (*p1 < *p0)
            {
                long t = *p1;
                *p1 = *p0;
                *p0 = t;
            }
            p0++;
            p1++;
        }
    }
}

/*

.L3:
	cmpl	%r11d, %r8d
	jge	.L7

    //只使用一次跳转
	movl	(%rdx), %r9d
	movl	(%rax), %r10d
	cmpl	%r10d, %r9d
	jge	.L4
	movl	%r10d, (%rdx)
	movl	%r9d, (%rax)


	jmp	.L4
.L7:

*/