/*
 * ��92�⣺����λ������������ʵ�����º���
 * float_bits float_negate(float_bits f)
 * ����-f�����f��NaN,�򷵻�f
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    //���ж��Ƿ���NaN
    //��������������if-else
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