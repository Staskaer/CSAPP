/*
 * ��64�⣺ʵ�����¹��ܺ�����
 * ��x������λ��1ʱ����1�����򷵻�0
*/

#include <stdio.h>
#include <stdlib.h>

int at_odd_one(unsigned x)
{
    return !!(x & 0x55555555);
}

int main()
{
    printf("%d\n%d", at_odd_one(2), at_odd_one(5));

    system("pause");
}