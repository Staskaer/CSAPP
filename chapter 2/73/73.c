/*
 * ��73�⣺д����������ԭ�͵Ĵ���
 * int saturating_add(int x,int y)
 * ͬ�����������ͬ�����������TMax�����������TMin
*/

#include <stdio.h>
#include <stdlib.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    //x>0,y>0 sum<0---�����
    //x<0,y<0 sum>0---�����
    int h_over = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    int l_over = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);

    (h_over && (sum = INT_MAX)) || (l_over && (sum = INT_MIN));
    //��Щ��if-else����Щ���ɵķ�ʽ
    return sum;
}

int main()
{
    printf("%d", saturating_add(INT_MAX, 123));

    system("pause");
}