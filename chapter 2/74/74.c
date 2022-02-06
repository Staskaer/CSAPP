/*
 * 第74题：写出具有以下原型的函数
 * int tsub_ok(int x, int y)
 * 计算x-y，不溢出时返回1
*/

#include <stdio.h>
#include <stdlib.h>

int tsub_ok(int x, int y)
{
    int sub = x - y;

    //x<0,y>0,sub>0负溢出
    //x>0,y<0,sub<0正溢出
    int h_over = (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);
    int l_over = !(x & INT_MIN) && (y & INT_MIN) && (sub & INT_MIN);
    return h_over | l_over;
}

int main()
{
    printf("%d", tsub_ok(-1, INT_MAX));
    system("pause");
}