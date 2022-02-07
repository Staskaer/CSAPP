/*
 * 第94题：实现函数 folat_bits float_twice(float_bits f)
 * 实现乘2功能
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    //先判断是否是NaN
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    //然后需要根据非规格化和规格化进行处理
    if (exp)
    {
        //规格化
        if (!(frac >> 22))
        {
            //小数位不会溢出
            frac = frac << 1;
        }
        else if (!(exp ^ 0xfe))
        {
            //阶码位不会溢出
            exp++;
        }
        else
        {
            //溢出
            frac = 0;
            exp = 0xff;
        }
    }
    else
    {
        //非规格化
        if (!(frac >> 22))
        {
            //小数位不会溢出
            frac = frac << 1;
        }
        else
        {
            //小数位溢出，则转变成规格化
            exp++;
            frac = frac << 10 >> 9;
            /*
             * 此处说明：由于非规格化转变成规格化时阶码+1实际上对权没有任何贡献
             * 唯一有改变的是M从原来的f变成1+f
             * 所以只要考虑让1+f = 2 * f即可
             * 考虑左边0.f的两倍只要左移一位即可
             * 而现在的整数位为1，同时也检测出f的首位为1，
             * 所以把小数位首位置零然后整体左移一位即可
             * 如0.1101 ----> 1.1010（这样就是两倍）
            */
        }
    }

    return (sign << 31) | (exp << 23) | (frac);
}

int main()
{
    unsigned x = 0x05701000;

    printf("%#.8x\n", float_twice(x));
    system("pause");
}