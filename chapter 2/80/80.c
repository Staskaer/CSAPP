/*
 * 第80题： 编写函数threefourths()，计算x*3/4，它不会溢出，向零舍入
*/

#include <stdio.h>
#include <stdlib.h>

int three_fourths(int x)
{
    /*
     * 要保证不溢出，则应该先除以4再乘以3，但是舍入比较困难（相比之下）
     * 我们可以把整数32位拆分成30位和2位，其中前30位和舍入没有关系
     * 因为除以4只要移动2位，我们只考虑最后两位的舍入即可
     * 由于后两位无论怎么乘都不会溢出，我们对最后两位可以按照先乘法再除法的计算
     * 这样整数拆分比较巧妙
     * 注意，拆分出来的两位做和是原来的数
    */

    //先进行整数拆分
    int m = x & ~0x3;
    int l = x & 0x3;

    //负数标志位
    int neg = x & INT_MIN;

    //先对前30位进行计算
    int md4 = m >> 2;
    int md4m3 = md4 + (md4 << 1);

    //对最后两位进行计算
    int lm3 = l + (l << 1);
    int l_bias = (1 << 2) - 1;
    (neg && (lm3 = lm3 + l_bias));
    //这个偏置是因为要向0舍入
    int lm3d4 = lm3 >> 2;

    return md4m3 + lm3d4;
}

int main()
{
    printf("%d,%d", three_fourths(0xffffffff), (int)0xffffffff / 4 * 3);
    system("pause");
}