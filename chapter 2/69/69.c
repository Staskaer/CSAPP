/*
 * 第69题：实现原型为 unsigned rotate_left(unsigned x, int n)
 * 实现左移循环的功能
 * 示例 如果x=0x12345678
 * n=4 -> x=0x23456781
 * 注意n=0的情况
 * n的范围 [0,32)
*/

#include <stdio.h>
#include <stdlib.h>

unsigned rotate_left(unsigned x, int n)
{
    /*
     * 思路很简单，由于左移会损失最左边的n位
     * 于是先利用掩模提取出这些会损失掉的位
     * 然后把这些位重新移动到右边再做或运算
    */

    size_t len = sizeof(int) << 3;

    unsigned mask = ~((0x1 << (len - n)) - 1);
    unsigned temp = mask & x; //提取出前面要被移去的位

    temp = temp >> (len - n);

    //printf("%#.8x\n", mask);
    return (x << n) | temp;
}

int main()
{
    printf("%#.8x\n", rotate_left(0x12345678, 28));

    system("pause");
}