// long cread(long *xp)
// {
//     return (xp ? *xp : 0);
// }

//这个函数不能使用条件传送，写一个cread_alt，能用条件传送汇编

long cread_alt(long *xp)
{
    long temp = 0;
    if (xp == 0)
    {
        xp = &temp;
    }
    return *xp;
}

//gcc -O3 -S 61.cpp生成的汇编满足要求
//但是优化的很多...

/*
这是优化后的汇编
.LFB0:
	.seh_endprologue
	xorl	%eax, %eax      #temp = 0
	testq	%rcx, %rcx      #xp==0
	je	.L1                 #xp==0 ->return 0
	movl	(%rcx), %eax    #else ->reruen *xp
.L1:
	ret

*/