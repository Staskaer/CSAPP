// long cread(long *xp)
// {
//     return (xp ? *xp : 0);
// }

//�����������ʹ���������ͣ�дһ��cread_alt�������������ͻ��

long cread_alt(long *xp)
{
    long temp = 0;
    if (xp == 0)
    {
        xp = &temp;
    }
    return *xp;
}

//gcc -O3 -S 61.cpp���ɵĻ������Ҫ��
//�����Ż��ĺܶ�...

/*
�����Ż���Ļ��
.LFB0:
	.seh_endprologue
	xorl	%eax, %eax      #temp = 0
	testq	%rcx, %rcx      #xp==0
	je	.L1                 #xp==0 ->return 0
	movl	(%rcx), %eax    #else ->reruen *xp
.L1:
	ret

*/