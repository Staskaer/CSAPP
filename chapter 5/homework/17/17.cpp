

#include <limits.h>
#define K sizeof(unsigned long)

void *basic_memset(void *s, int c, size_t n)
{
    if (n < K)
    //小于k直接写
    {
        size_t cnt = 0;
        unsigned char *schar = s;
        while (cnt < n)
        {
            *schar++ = (unsigned char)c;
            cnt++;
        }
    }
    else
    {
        //否则一次写8个字节
        //先获取这8个字节的数据
        unsigned long word = 0;
        for (int i = 0; i < K; ++i)
        {
            word <<= K * CHAR_BIT;
            word += (unsigned char)c;
        }

        //类似循环展开，一次写8个字节
        size_t cnt = 0;
        unsigned long *slong = s;
        while (cnt < n)
        {
            *slong++ = word;
            cnt += K;
        }

        //剩下的部分
        unsigned char *schar = slong;
        while (cnt < n)
        {
            *schar++ = (unsigned char)c;
            cnt++;
        }
    }
    return s;
}