/*
 * 第96题（四星）：遵循位级浮点编码标准，编写以下函数
 * int float_i2f(float_bits f)
 * 计算转换成int类型的f，若不能表示，则返回0x80000000
 * 
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

//似乎是标准答案
int float_f2i(float_bits f)
{
    /*
     * 浮点数的处理主要看阶码
    */

    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    /* Create normalized value with leading one inserted, and rest of significand in bits 8--30.*/
    //由于非规格化的值一定小于1，即被强转为0，此处计算的是M的值（忽视了小数点后的表示）
    //‘8’的来源是规格化数的M = 1 + f中的‘1’
    unsigned val = 0x80000000u + (frac << 8);
    if (exp < 127)
    {
        /* Absolute value is < 1 */
        //阶码小于偏置，则不会出现大于1的数
        return (int)0;
    }
    if (exp > 158)
        /* Overflow */
        //阶码太大，导致溢出，同时将正无穷和nan包含在内
        return (int)0x80000000u;
    /* Shift val right */
    //计算M * 2^E，其中158 - exp是E
    val = val >> (158 - exp);
    /* Check if out of range */
    //再次检查是否溢出，顺便带上符号
    if (sign)
    {
        /* Negative */
        return val > 0x80000000u ? (int)0x80000000u : -(int)val;
    }
    else
    {
        /* Positive */
        return val > 0x7FFFFFFF ? (int)0x80000000u : (int)val;
    }
}

int main()
{
    unsigned x = 0x45100152;
    printf("%#.8x\n", (unsigned)float_f2i(x));

    system("pause");
}