/*
 * 第55题：
 * 在你能够访问的不同机器上，使用show_bytes
 * 编译并运行来确定使用机器的字节顺序
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    /*
     * 此函数的作用是将输入的指向基本类型的指针看作unsigned char数组
     * 由于其他基本类型一般都是char类型长度的整数倍
     * 所以可以将基本类型按照占用位数分解成多个char并打印出来
     * 
     * 实际上是使用强制类型转换来规避基本类型
    */
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    printf("show_int function, sizeof(int) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * 将int类型来强制转换成char数组并逐位输出
    */
}

void show_float(float x)
{
    printf("show_float function, sizeof(float) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * 将float类型来强制转换成char数组并逐位输出
    */
}

void show_pointer(void *x)
{
    printf("show_pointer function, sizeof(void *) is %d\n", (int)sizeof(void *));

    show_bytes((byte_pointer)&x, sizeof(void *));
    /*
     * 将void *类型来强制转换成char数组并逐位输出
    */
}

int main()
{
    int val = 1;
    show_int(val);
    show_float((float)val);
    show_pointer((void *)&val);

    system("pause");

    return 0;
}
/*
 * 我使用的机器是64位Windows。
 * 观察结果是小端法机器
 * 其中int 4位，float 4位，指针8位
*/