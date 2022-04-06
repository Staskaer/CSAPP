#include <stdio.h>

//д�������Ӧ��c����
//����x,y,zͨ��%rdi,%rsi,%rdx����
/*

decode2:
    subq    %rdx, %rsi      ;y=y-z
    imulq   %rsi, %rdi      ;x=x*y  ---> x*(y-z)
    movq    %rsi, %rax      ;temp=y
    salq    $63,  %rax      
    sarq    $63,  %rax      ;(temp<<63)>>63
    xor     %rdi, %rax      ;���
    ret

    */

long decode2(long x, long y, long z)
{
    y = y - z;
    x = x * y;
    return (x ^ ((y << 63) >> 63));
}

//��gcc -Og -S 58.cpp���ɵĻ����ͬһĿ¼��