/*
 * ��62�⣺��дint_shifts_are_arithmetic()����
 * ��int���͵���ʹ���������ƵĻ���������ʱ����1����������0
*/

#include <stdio.h>
#include <stdlib.h>

void int_shifts_are_arithmetic()
{
    int x = 0xff000000;
    printf("%d", ((x >> ((sizeof(int) - 1) << 3)) == 0xffffffff));
    /*
     * 0xff000000��������3�ֽڱ��0xffffffff
    */
}

int main()
{
    int_shifts_are_arithmetic();
    system("pause");
}