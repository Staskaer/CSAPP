/*
 * ��74�⣺д����������ԭ�͵ĺ���
 * int tsub_ok(int x, int y)
 * ����x-y�������ʱ����1
*/

#include <stdio.h>
#include <stdlib.h>

int tsub_ok(int x, int y)
{
    int sub = x - y;

    //x<0,y>0,sub>0�����
    //x>0,y<0,sub<0�����
    int h_over = (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);
    int l_over = !(x & INT_MIN) && (y & INT_MIN) && (sub & INT_MIN);
    return h_over | l_over;
}

int main()
{
    printf("%d", tsub_ok(-1, INT_MAX));
    system("pause");
}