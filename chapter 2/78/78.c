/*
 * 第78题：写出具有以下原型的代码 int divide_power2(int x,int k)
 * 实现以下功能：x/2^k
 * 0<=k<w-1
 * 要求遵循位级整数编程（不允许使用乘除法）
*/

#include <stdio.h>
#include <stdlib.h>

int divide_power2(int x, int k)
{
    //注意c语言是向0取整的（本代码的推导也在书上）
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