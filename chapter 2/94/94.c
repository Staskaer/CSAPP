/*
 * ��94�⣺ʵ�ֺ��� folat_bits float_twice(float_bits f)
 * ʵ�ֳ�2����
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    //���ж��Ƿ���NaN
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    //Ȼ����Ҫ���ݷǹ�񻯺͹�񻯽��д���
    if (exp)
    {
        //���
        if (!(frac >> 22))
        {
            //С��λ�������
            frac = frac << 1;
        }
        else if (!(exp ^ 0xfe))
        {
            //����λ�������
            exp++;
        }
        else
        {
            //���
            frac = 0;
            exp = 0xff;
        }
    }
    else
    {
        //�ǹ��
        if (!(frac >> 22))
        {
            //С��λ�������
            frac = frac << 1;
        }
        else
        {
            //С��λ�������ת��ɹ��
            exp++;
            frac = frac << 10 >> 9;
            /*
             * �˴�˵�������ڷǹ��ת��ɹ��ʱ����+1ʵ���϶�Ȩû���κι���
             * Ψһ�иı����M��ԭ����f���1+f
             * ����ֻҪ������1+f = 2 * f����
             * �������0.f������ֻҪ����һλ����
             * �����ڵ�����λΪ1��ͬʱҲ����f����λΪ1��
             * ���԰�С��λ��λ����Ȼ����������һλ����
             * ��0.1101 ----> 1.1010����������������
            */
        }
    }

    return (sign << 31) | (exp << 23) | (frac);
}

int main()
{
    unsigned x = 0x05701000;

    printf("%#.8x\n", float_twice(x));
    system("pause");
}