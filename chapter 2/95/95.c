/*
 * 第95题：实现以下功能原函数，遵顼浮点数编码规则
 * float_bits float_half(float_bits f)
 * 实现除以2
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    //nan
    if (!(exp ^ 0xff) && frac)
    {
        return f;
    }

    if (exp)
    {
        //规格化
        if (exp != 1)
        {
            //阶码不为1的规格化直接阶码-1
            exp--;
        }
        else
        {
            //阶码为1的规格化要转化成非规格化
            if (frac)
            {
                //小数位非0，要进行舍入
                if ((frac >> 1) & 1)
                {
                    frac++;
                    frac >>= 1;
                    frac |= 0x400000;
                    --exp;
                }
                else
                {
                    frac >>= 1;
                    frac |= 0x400000;
                    --exp;
                }
            }
            else //小数位为0,手动置数
            {
                exp--;
                frac = 0x003fffff;
            }
        }
    }
    else
    {
        //非规格化
        if (frac)
        {
            //小数位非0舍入
            if ((frac >> 1) & 1)
            {
                frac++;
                frac >>= 1;
            }
            else
            {
                frac >>= 1;
            }
        }
        else
        {
            //小数位为0
            frac = 0x003fffff;
        }
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main()
{
    unsigned x = 0x00456201;
    printf("%#.8x\n", float_half(x));
    printf("%#.8x\n", (unsigned)((float)x / 2)); //这是正确的位表示
    system("pause");
}