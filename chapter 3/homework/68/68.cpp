#define A 9
#define B 5

typedef struct
{
    int x[A][B];
    /*
    176 < 4*A*B <= 184 --->44 < A*B <= 46
    */
    long long y;
} str1;

typedef struct
{
    char array[B];
    int t;
    short s[A];
    long long u;
    /*
    考虑对齐，4<B<=8, 20<2A+B<=28
    */
} str2;

void getVal(str1 *p, str2 *q)
{
    long long v1 = q->t;
    long long v2 = q->u;
    p->y = v1 + v2;
}

/*
p in %rdi, q in %rsi

setVal:
    movslq  8(%rsi),    %rax
    addq    32(%rsi),   %rax
    movq    %rax,       184(%rdi)
    ret
*/

//gcc -Og -S 68.cpp 生成的基本一模一样