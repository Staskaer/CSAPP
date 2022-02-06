/*
 * 第73题：写出具有如下原型的代码
 * int saturating_add(int x,int y)
 * 同正常的溢出不同，正溢出返回TMax，负溢出返回TMin
*/

#include <stdio.h>
#include <stdlib.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    //x>0,y>0 sum<0---正溢出
    //x<0,y<0 sum>0---负溢出
    int h_over = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    int l_over = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);

    (h_over && (sum = INT_MAX)) || (l_over && (sum = INT_MIN));
    //有些像if-else，有些讨巧的方式
    return sum;
}

int main()
{
    printf("%d", saturating_add(INT_MAX, 123));

    system("pause");
}