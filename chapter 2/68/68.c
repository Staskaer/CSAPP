/*
 * 第68题：按照给定的数字k将最低k位全部设置为1
 * 示例 6 -> 0x3f
 * 注意n=w的情况
*/

#include <stdio.h>
#include <stdlib.h>

int lower_one_mask(int n)
{
    /*
     * 注意 (1<<n)-1这样的使用左移运算符会在n=w时失效
     * 不过可以考虑全是1的unsigned来右移完成。
     * 这样是一个讨巧的方法，也可以说是妥协，因为n=0时失效
     * 不过题目要求n在[1,w]中
     */
    unsigned x = ~0;
    return x >> ((sizeof(int) << 3) - n);
}

int main()
{
    printf("%#.8x\n", lower_one_mask(1));

    system("pause");
}