/*
 * ��95�⣺ʵ�����¹���ԭ���������︡�����������
 * float_bits float_half(float_bits f)
 * ʵ�ֳ���2
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    //nan
    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    if (exp)
    {
        //���
        if (exp != 1)
        {
            //���벻Ϊ1�Ĺ��ֱ�ӽ���-1
            exp--;
        }
        else
        {
            //����Ϊ1�Ĺ��Ҫת���ɷǹ��
            if (frac)
            {
                //С��λ��0��Ҫ��������
                if ((frac >> 1) & 1)
                {
                    frac++;
                    frac >>= 1;
                    frac |= 0x400000;
                    --exp;
                }
                else
                {
                    frac >>= 1;
                    frac |= 0x400000;
                    --exp;
                }
            }
            else //С��λΪ0,�ֶ�����
            {
                exp--;
                frac = 0x003fffff;
            }
        }
    }
    else
    {
        //�ǹ��
        if (frac)
        {
            //С��λ��0����
            if ((frac >> 1) & 1)
            {
                frac++;
                frac >>= 1;
            }
            else
            {
                frac >>= 1;
            }
        }
        else
        {
            //С��λΪ0
            frac = 0x003fffff;
        }
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main()
{
    unsigned x = 0x00456201;
    printf("%#.8x\n", float_half(x));
    printf("%#.8x\n", (unsigned)((float)x / 2)); //������ȷ��λ��ʾ
    system("pause");
}