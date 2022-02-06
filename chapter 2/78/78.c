/*
 * ��78�⣺д����������ԭ�͵Ĵ��� int divide_power2(int x,int k)
 * ʵ�����¹��ܣ�x/2^k
 * 0<=k<w-1
 * Ҫ����ѭλ��������̣�������ʹ�ó˳�����
*/

#include <stdio.h>
#include <stdlib.h>

int divide_power2(int x, int k)
{
    //ע��c��������0ȡ���ģ���������Ƶ�Ҳ�����ϣ�
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));

    return x >> k;
}

int main()
{
    int x = 0x80000007;
    printf("%d,%d", divide_power2(x, 2), x / 4);

    system("pause");
}