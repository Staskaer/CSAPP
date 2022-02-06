/*
 * 第71题：实现以下功能函数
 * 使用补码运算和算数右移
 * 函数抽取指定的字节，然后把它符号扩展为一个32位int
 * 
 * 问题：水平不高的代码的问题在哪里
 * 如何改正（只使用左右位移和一个减法）
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned packed_t;

//水平不高的代码
int bad_xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xff;

    /*
     * 此处只是简单的将高位置零
     * 取出的字节是负值，则会错误的返回正值
    */
}

int xbyte(packed_t word, int bytenum)
{
    unsigned left_move = (3 - bytenum) << 3;
    unsigned right_move = 3 << 3;
    return (int)word << left_move >> right_move;

    /*
     * 使用左移来选择到被导出的位
     * 使用算术右移来将其移动到末尾进行扩展
    */
}

int main()
{
    printf("%#.8x\n", xbyte(0x8008ff00, 3));
    system("pause");
}