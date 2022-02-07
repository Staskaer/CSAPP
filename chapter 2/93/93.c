/*
 * ��93�⣺���︡��λ���������ʵ�����º���
 * float_bits float_absval(float_bits f)
 * �������ֵ
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    //unsigned sign = f >> 31;
    //����Ҫ�õ�����λ��ֱ�Ӷ�������
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