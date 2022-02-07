/*
 * 第92题：遵顼位级浮点编码规则，实现以下函数
 * float_bits float_negate(float_bits f)
 * 计算-f，如果f是NaN,则返回f
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    //先判断是否是NaN
    //浮点规则里可以用if-else
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    return ((sign ^ 0x1) << 31) | (exp << 23) | frac;
}

int main()
{
    unsigned x = 0xff800001;
    printf("%#.8x\n", float_negate(x));
    system("pause");
}