/*
 * 第63题：将代码补充完整。
 * 函数srl用算数右移（由xsra给出）来完成逻辑右移
 * 后面的其他操作不包括右移或除法
 * 函数sra用逻辑右移（由xsrl给出）来完成算数右移
 * 后面的其他操作不包括右移或除法
 * 
 * 可以通过计算8*sizeof(int)来确定数据类型int中的位数w
 * 位移量k的取值范围位0 ~ w-1
*/

#include <stdio.h>
#include <stdlib.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    xsra = xsra & (~(((0x1 << k) - 1) << ((sizeof(int) << 3) - k)));
    /*算数右移与逻辑右移的区别在于高位是否需要补1
     * 由于此时不需要补1，因此可以用0x00ffffff这样的掩模做&运算
     * 获取掩模可以先把1左移k位减去1，这样得到一个长度为k的低位全为1的值
     * 将这个值的全为1的长度也与掩模中高位0的长度相等
     * 因此再次向左移取反，左移的长度是int类型的总长减去k
     */

    return xsra;
}

int sra(unsigned x, int k)
{
    int xsrl = (unsigned)x >> k;
    int test = 0x1 << ((sizeof(int) << 3) - 1 - k);
    test &= xsrl;
    test = ~(test - 1);
    xsrl = xsrl | test;
    /*
     * 与上面的不同，因为不能无脑补1，需要先确定最高位
     * 其中test初始化为右侧与xsrl长度相等的数据（两者左侧全为0）
     * 然后test与xsrl做&运算，得到符号位，-1后的低位全是1，求反得到掩模
     * 当符号位为0时，掩模全为0，不改变原来的值
    */
    return xsrl;
}

int main()
{
    printf("%d , %d\n", srl(0xff000000, 8), (unsigned)0xff000000 >> 8);

    printf("%d , %d", sra(0xff000000, 8), (int)0xff000000 >> 8);
    system("pause");
}