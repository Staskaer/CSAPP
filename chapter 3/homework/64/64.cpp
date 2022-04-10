#define R 7
#define S 5
#define T 13

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
    *dest = A[R][S][T];
    return sizeof(A);
}

/*
i in %rdi, j in %rsi, k in %rdx, dest in %rcx

公式：
如果定义数组A[R][S][T]
&A[i][j][k] = A + L(i*S*T + j*T + k)


store_ele:
    leaq    (%rsi,%rsi,2)   %rax    #%rax = 3*j
    leaq    (%rsi,%rax,4)   %rax    #%rax = 13*j
                                    #j*T ==> T = 13

    movq    %rdi,           %rsi    #j = i
    salq    $6,             %rsi    #j << 6 ==> j * 2^6
    addq    %rsi,           %rdi    #i += j ==> i * 2^6 + 1
                                    #i*S*T ==> S*T = 2^6 + 1 ==> S = 5
    addq    %rax,           %rdi    #i += rax
    addq    %rdi,           %rdx    #k += i
    movq    %A(,%rdx,8),    %rax    #rax = 8*k + A
    movq    %rax,           (%rcx)  #*dest = A[i][j][k]
    movl    $3640,          %ecx    #这是总长度
                                    #R*S*T*L=3640 ===> R = 7
    ret
*/

//gcc -Og -S 64.cpp感觉不太一样捏
//long这里是4位的，但是书上应该是8位的