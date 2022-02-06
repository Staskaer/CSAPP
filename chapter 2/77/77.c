/*
 * 第77题：生成一段代码，将整数变量乘以不同常数因子K
 * 只使用+、-、<<运算，对于指定K，写出表达式
 * 不超过3个运算
 * K=17、-7、60、-112
*/

#include <stdio.h>
#include <stdlib.h>

void k(int k, int x)
{
    if (k == 17)
    {
        x = (x << 4) + x;
    }
    if (k == -7)
    {
        x = x - (x << 3);
    }
    if (k == 60)
    {
        x = (x << 6) - (x << 2);
    }
    if (k == -112)
    {
        x = (x << 4) - (x << 7);
    }
    printf("%d\n", x);
}

int main()
{
    int k_ = 60;
    int x = 10;
    k(k_, x);

    system("pause");
}