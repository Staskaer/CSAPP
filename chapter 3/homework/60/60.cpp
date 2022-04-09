/*
翻译汇编并转化成c代码

long loop(long x,int n)
x--rdi, n---esi


loop:
    movl    %esi,   %ecx
    movl    $1,     %edx    #mask，因为是用rdx来判断循环的
    movl    $0,     %eax    #result
    jmp     .L2
.L3:
    movq    %rdi,   %r8     #r8 = x
    andq    %rdx,   %r8     #r8 = x & mask
    orq     %r8,    %rax    #result = r8 | resulr
    salq    %cl,    %rdx    #rdx(mask) << (n%256) 因为只取了低位
.L2:
    testq   %rdx,   %rdx    #与运算
    jne     .L3             #非0跳转
    rep;ret

*/

long loop(long x, int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask <<= (n % 256))
    {
        result |= (x | mask);
    }
    return result;
}