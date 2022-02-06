/*
 * 第75题：计算x*y的完整2w位中高w位
 * 函数原型 unsigned unsigned_high_prob(unsigned x,unsigned y)
 * 提供函数计算x、y在采用补码形式的情况下，x·y的高w位
 * 提示：x`·y` = x·y + (x[w-1]·y+y[w-1]·x)·2^w + x[w-1]·y[w-1]·2^2w
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int signed_high_prod(int x, int y)
{
    //计算有符号的乘法高w位
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

unsigned unsigned_high_prob(unsigned x, unsigned y)
{
    unsigned h_t = signed_high_prod(x, y);
    unsigned x_ = x >> 31;
    unsigned y_ = y >> 31;
    return h_t + x_ * y + y_ * x + ((x_ * y_) << 31);

    /*
     * 推导可以看书，但是总感觉使用了乘法有些作弊的嫌疑
    */
}

//这是测试用的可以返回正确答案的函数
unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

int main()
{
    unsigned x = 0x12345678;
    unsigned y = 0xFF432FFF;
    printf("%#.8x\n", unsigned_high_prob(x, y));
    printf("%#.8x", another_unsigned_high_prod(x, y));
    system("pause");
}