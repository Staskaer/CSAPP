/*
 * ��79�⣺��дmul3div4�Ĵ��룬����x*3/4
 * ��ѭ����λ���������
*/

#include <stdio.h>
#include <stdlib.h>

int mul3div4(int x)
{
    //ҲҪע��ȡ�������⣨�����ڸ����������������ǲ���ȷ�ģ���
    int neg = x & INT_MIN;
    int mul3 = (x << 1) + x;
    (neg && (mul3 = mul3 + (1 << 2) - 1));

    return mul3 >> 2;
}

int main()
{
    printf("%d", mul3div4(12));

    system("pause");
}