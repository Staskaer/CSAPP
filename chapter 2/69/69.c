/*
 * ��69�⣺ʵ��ԭ��Ϊ unsigned rotate_left(unsigned x, int n)
 * ʵ������ѭ���Ĺ���
 * ʾ�� ���x=0x12345678
 * n=4 -> x=0x23456781
 * ע��n=0�����
 * n�ķ�Χ [0,32)
*/

#include <stdio.h>
#include <stdlib.h>

unsigned rotate_left(unsigned x, int n)
{
    /*
     * ˼·�ܼ򵥣��������ƻ���ʧ����ߵ�nλ
     * ������������ģ��ȡ����Щ����ʧ����λ
     * Ȼ�����Щλ�����ƶ����ұ�����������
    */

    size_t len = sizeof(int) << 3;

    unsigned mask = ~((0x1 << (len - n)) - 1);
    unsigned temp = mask & x; //��ȡ��ǰ��Ҫ����ȥ��λ

    temp = temp >> (len - n);

    //printf("%#.8x\n", mask);
    return (x << n) | temp;
}

int main()
{
    printf("%#.8x\n", rotate_left(0x12345678, 28));

    system("pause");
}