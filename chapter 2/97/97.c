/*
 * ��97�⣨���ǣ�������λ���������ʵ�ֺ���
 * float_bits float_i2f(int i)
 * ʵ��intתfloat
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

int leftmost_one(unsigned x)
{
    unsigned sizeof_unsigned = sizeof(unsigned);
    unsigned w = sizeof_unsigned << 3;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x & ((~x >> 1) | INT_MIN);
}

float_bits float_i2f(int i)
{
    /*
     * �˷�����˼·�������ϵ�����תfloat�Ĺ��̣���������p82
     * Ҫ�õ�66���л�ȡ������1��λ����Ϊ�˹������
    */

    unsigned sign = 0;
    unsigned exp = 0;
    unsigned frac = 0;
    unsigned bias = 127;
    if (i == INT_MIN)
    {
        return 0xCF000000;
    }
    else //treat negative as positive
    {
        if (i < 0)
        {
            sign = 1;
            i = -i;
        }
        int mask = leftmost_one(i);
        int move = 0;
        if (mask >= 0x00800000) //rightshift
        {
            while (mask != 0x00800000)
            {
                mask >>= 1;
                ++move;
            }

            if ((i & ((1 << (move + 1)) - 1)) > (1 << move)) //round to even(>1/2)
            {
                i >>= move;
                i += 1;
            }
            else if ((i & ((1 << (move + 1)) - 1)) < (1 << move)) //(<1/2)
            {
                i >>= move;
            }
            else // 1/2
            {
                if ((i >> move) & 1) //round to even
                {
                    i >>= move;
                    i += 1;
                }
                else
                {
                    i >>= move;
                }
            }
        }
        else //leftshift
        {
            while (mask != 0x00800000)
            {
                mask <<= 1;
                --move;
            }
            i <<= -move;
        }
        frac = i & 0x7FFFFF; //Discard the 24th bit one
        exp = bias + 22 + move;
    }
    return (sign << 31) | (exp << 23) | frac;
}