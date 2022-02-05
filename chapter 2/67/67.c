/*
 * 第六十七题：编写int_size_is_32()的函数，在int为32位的机器上显示1
 * 不允许使用sizeof运算符
 * 给出bad_int_size_is_32()，其不能很好的在一些机器上运行
 * 
 * bad...中有哪个方面没有遵循c语言规范
 * 修改代码，使其能在int至少为32位的机器上运行
 * 修改代码，使其能在int至少为16位的机器上运行
*/

#include <stdio.h>
#include <stdlib.h>

int bad_int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 32;
    //报warning：left shift count >= width of type [-Wshift-count-overflow]
    return set_msb && !beyond_msb;

    /*
     * 回答：32位机器上32位左移是未定义的 -- undefined
    */
}
int int_size_is_32()
{
    //至少运行在32位机器上

    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_16()
{
    //至少运行在16位机器上

    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main()
{
    printf("%d,%d", int_size_is_32(), int_size_is_32_16());
    system("pause");
}