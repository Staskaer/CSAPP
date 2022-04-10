struct a_struct
{
    long idx;
    long x[4];
};
#define CNT 7

/*以上为未知参数*/

typedef struct
{
    int first;
    a_struct a[CNT];
    int last;
} b_struct;

void test(long i, b_struct *bp)
{
    int n = bp->first + bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

/*
mov     0x120(%rsi),    %ecx    #显然rsi是bp，考虑对齐，0X11B<a[CNT]<=0X120
add     (%rsi),         %ecx    #ecx是n
lea     (%rdi,%rdi,4),  %rax    #rax=5*rdi
lea     (%rsi,%rax,8),  %rax    #rax = bp + 40*rdi，计算出了a[i]的数组偏移
mov     0x8(%rax),      %rdx    #rdx为bp->a[i] = (bp + 40 * rdi + 8)
                                #显然，struct_a大小为40
                                #struct_b中开始有个int，所以+8的偏移说明s_a的开始是一个long
movslq  %ecx,           %rcx
mov     %rcx            0x10(%rax,%rdx,8)
                                #rcx是n的值
                                #而ap->x[ap->idx]的偏移是rax+8*rdx+16
                                #理论上是(a->x) + (ap+0)*len
                                #=rax+8+8 + rdx*len（a->x = ap + 8 = rdx +8 = rax + 16）
                                #=rax + rdx*len + 16
                                #所以len = 8
                                #而总占用40个字节，所以为long类型，4个
                                #利用0X11B<a[CNT]<=0X120 --->CNT = 7
retq

*/