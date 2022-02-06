/*
 * 第79题：编写mul3div4的代码，计算x*3/4
 * 遵循整数位级编码规则
*/

#include <stdio.h>
#include <stdlib.h>

int mul3div4(int x)
{
    //也要注意取整的问题（右移在负数除法的舍入上是不正确的）、
    int neg = x & INT_MIN;
    int mul3 = (x << 1) + x;
    (neg && (mul3 = mul3 + (1 << 2) - 1));

    return mul3 >> 2;
}

int main()
{
    printf("%d", mul3div4(12));

    system("pause");
}