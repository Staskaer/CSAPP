/*
 * ��96�⣨���ǣ�����ѭλ����������׼����д���º���
 * int float_i2f(float_bits f)
 * ����ת����int���͵�f�������ܱ�ʾ���򷵻�0x80000000
 * 
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

//�ƺ��Ǳ�׼��
int float_f2i(float_bits f)
{
    /*
     * �������Ĵ�����Ҫ������
    */

    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    /* Create normalized value with leading one inserted, and rest of significand in bits 8--30.*/
    //���ڷǹ�񻯵�ֵһ��С��1������ǿתΪ0���˴��������M��ֵ��������С�����ı�ʾ��
    //��8������Դ�ǹ������M = 1 + f�еġ�1��
    unsigned val = 0x80000000u + (frac << 8);
    if (exp < 127)
    {
        /* Absolute value is < 1 */
        //����С��ƫ�ã��򲻻���ִ���1����
        return (int)0;
    }
    if (exp > 158)
        /* Overflow */
        //����̫�󣬵��������ͬʱ���������nan��������
        return (int)0x80000000u;
    /* Shift val right */
    //����M * 2^E������158 - exp��E
    val = val >> (158 - exp);
    /* Check if out of range */
    //�ٴμ���Ƿ������˳����Ϸ���
    if (sign)
    {
        /* Negative */
        return val > 0x80000000u ? (int)0x80000000u : -(int)val;
    }
    else
    {
        /* Positive */
        return val > 0x7FFFFFFF ? (int)0x80000000u : (int)val;
    }
}

int main()
{
    unsigned x = 0x45100152;
    printf("%#.8x\n", (unsigned)float_f2i(x));

    system("pause");
}