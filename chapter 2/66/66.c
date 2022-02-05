/*
 * 第66题：实现如下功能代码：表示x在二进制中最左端的1的掩码
 * 示例 0xff00 -> 0x8000 0x6600 -> 0x4000 0x0 -> 0
 * 应遵循位级编程规范，且最多包含15个运算符
*/

#include <stdio.h>
#include <stdlib.h>

int left_most(unsigned x)
{

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    //以上操作可以让第一个1的右边全是1
    //然后取反可以让第一个1的左边全是1，右边全是0
    //然后向右移动一位，与原数做与运算可以得到掩模
    //由于INT_MIN取反后全为0，因此取反移位后强制让首位变成1

    return x & ((~x >> 1) | INT_MIN);
}
int main()
{
    printf("%d,%d", left_most(0x6600), 0x4000);

    system("pause");
}