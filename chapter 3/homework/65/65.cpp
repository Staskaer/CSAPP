#define M 15

void transpode(long A[M][M])
{
    long i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < i; j++)
        {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}

/*

.L2:
    movq    (%rdx), %rcx    #%rdx保存指向A[i][j]的指针
    movq    (%rax), %rsi    #%rax保存指向A[j][i]的指针
    movq    %rsi,   (%rdx)
    movq    %rcx,   (%rax)  #这两步是移动交换
    addq    $8,     %rdx    #A[i][j+1]
    addq    $120,   %rax    #A[i+1][j] ===> M*8 = 120 ->M=15
    cmpq    %rdi,   %rax    
    jne     .L6


*/

//gcc -O1 -S 65.cpp 生成的汇编差距很大捏