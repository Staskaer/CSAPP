/*
 * 本文件涉及55-60题，因为56-60题需要用到55题的函数
 * 
 * 第55题：
 * 在你能够访问的不同机器上，使用show_bytes
 * 编译并运行来确定使用机器的字节顺序
 * 
 * 第56题：试着用不同的值来运行show_byte
 * 
 * 第57题：编写show_short,show_long,show_double的代码
 * 
 * 第58题：编写能够显示当前机器是大端还是小端的机器
 * 
 * 第59题：编写c语言表达式，生成由x最低有效字节和y剩下的字节组成
 * 
 * 第60题：将一个w位的字中的字节从0到w/8-1编号。写出c函数代码，返回无符号值
 * 其中x的字节i被换成字节b
 * 示例 replace_byte(0x12345678,2,0xab) --> 0x12ab5678
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

//第55题内容
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

//第57题内容
void show_short(short x)
{
    printf("show_short function, sizeof(short) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * 将short类型来强制转换成char数组并逐位输出
    */
}

void show_long(long x)
{
    printf("show_long function, sizeof(long) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * 将long类型来强制转换成char数组并逐位输出
    */
}

void show_double(double x)
{
    printf("show_double function, sizeof(double) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * 将double类型来强制转换成char数组并逐位输出
    */
}

//第58题内容
void is_little_endian()
{
    short val = 1;
    if (((byte_pointer)&val)[0] == 1)
        printf("is little endian\n");
    else
        printf("is not little endian\n");

    //如果是按照题目那样是小端输出1，大端输出0可以像这样写
    //但我认为此处用if-else的输出更加明了
    //printf("%d", ((byte_pointer)&val)[0]);
}

//第59题
void generate(int x, int y, size_t len_y)
{
    //x,y不一定是int类型，但要传递sizeof(y)

    printf("y : ");
    for (size_t i = 0; i < len_y; i++)
        printf("%.2x ", ((byte_pointer)&y)[i]);

    ((byte_pointer)&y)[0] = ((byte_pointer)&x)[0];
    printf("\ny(now) :");
    for (size_t i = 0; i < len_y; i++)
        printf("%.2x ", ((byte_pointer)&y)[i]);
    printf("\n");
}

//第60题
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    //由于已知机器是小端法，故本题实际上输出正常的数字表示顺序
    printf("\nx : ");
    for (int i = 3; i >= 0; i--)
        printf("%.2x ", ((byte_pointer)&x)[i]);
    ((byte_pointer)&x)[i] = b;
    printf("\nx(now) : ");
    for (int i = 3; i >= 0; i--)
        printf("%.2x ", ((byte_pointer)&x)[i]);
    return x;
}

int main()
{
    //55题-57题测试代码
    short val = 1;

    show_int((int)val);
    show_float((float)val);
    show_pointer((void *)&val);
    show_short((short)val);
    show_long((long)val);
    show_double((double)val);

    //58题测试代码
    is_little_endian();

    //59题测试代码
    int x = 1;
    short y = 1234;
    generate(x, y, sizeof(y));

    //60题测试代码
    replace_byte(0x12345678, 2, 0xab);

    system("pause");

    return 0;
}
/*
 * 我使用的机器是64位Windows。
 * 观察结果是小端法机器
 * 其中int 4位，float 4位，指针8位
*/