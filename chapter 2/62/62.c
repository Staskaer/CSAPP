/*
 * 第62题：编写int_shifts_are_arithmetic()函数
 * 对int类型的数使用算数右移的机器上运行时生成1，否则生成0
*/

#include <stdio.h>
#include <stdlib.h>

void int_shifts_are_arithmetic()
{
    int x = 0xff000000;
    printf("%d", ((x >> ((sizeof(int) - 1) << 3)) == 0xffffffff));
    /*
     * 0xff000000算数右移3字节变成0xffffffff
    */
}

int main()
{
    int_shifts_are_arithmetic();
    system("pause");
}