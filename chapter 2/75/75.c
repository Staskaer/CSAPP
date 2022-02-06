/*
 * ��75�⣺����x*y������2wλ�и�wλ
 * ����ԭ�� unsigned unsigned_high_prob(unsigned x,unsigned y)
 * �ṩ��������x��y�ڲ��ò�����ʽ������£�x��y�ĸ�wλ
 * ��ʾ��x`��y` = x��y + (x[w-1]��y+y[w-1]��x)��2^w + x[w-1]��y[w-1]��2^2w
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int signed_high_prod(int x, int y)
{
    //�����з��ŵĳ˷���wλ
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
     * �Ƶ����Կ��飬�����ܸо�ʹ���˳˷���Щ���׵�����
    */
}

//���ǲ����õĿ��Է�����ȷ�𰸵ĺ���
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