#include <stdio.h>

//写出与汇编对应的c代码
//其中x,y,z通过%rdi,%rsi,%rdx传递
/*

decode2:
    subq    %rdx, %rsi      ;y=y-z
    imulq   %rsi, %rdi      ;x=x*y  ---> x*(y-z)
    movq    %rsi, %rax      ;temp=y
    salq    $63,  %rax      
    sarq    $63,  %rax      ;(temp<<63)>>63
    xor     %rdi, %rax      ;异或
    ret

    */

long decode2(long x, long y, long z)
{
    y = y - z;
    x = x * y;
    return (x ^ ((y << 63) >> 63));
}

//用gcc -Og -S 58.cpp生成的汇编在同一目录下