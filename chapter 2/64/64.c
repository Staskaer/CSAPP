/*
 * 第64题：实现以下功能函数：
 * 当x中奇数位有1时返回1，否则返回0
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