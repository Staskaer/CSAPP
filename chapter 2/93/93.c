/*
 * 第93题：遵顼浮点位级编码规则，实现以下函数
 * float_bits float_absval(float_bits f)
 * 计算绝对值
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    //unsigned sign = f >> 31;
    //不需要用到符号位，直接丢弃即可
    unsigned exp = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;

    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    return (exp << 23) | frac;
}

int main()
{
    unsigned x = 0xf08fffff;
    printf("%#.8x", float_absval(x));
    system("pause");
}