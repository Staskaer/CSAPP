/*
 * 第72题：编写函数，将正数val复制到缓冲区buf中，
 * 但是只有当缓冲区有足够可用空间时才执行复制
 * 给出错误代码，当maxbytes很小时也能复制到缓冲区
 * 
 * 解释为什么错误发生
 * 修正
*/

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//错误代码
void bad_copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));

    /*
         * 错误原因：sizeof返回类型时unsigned
         * 在与int做运算时会被提升到unsigned，始终大于0，条件成立
        */
}

//修正代码
void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - (int)sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}
int main()
{
    system("color 1a");
    system("pause");
}