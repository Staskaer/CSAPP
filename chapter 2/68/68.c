/*
 * ��68�⣺���ո���������k�����kλȫ������Ϊ1
 * ʾ�� 6 -> 0x3f
 * ע��n=w�����
*/

#include <stdio.h>
#include <stdlib.h>

int lower_one_mask(int n)
{
    /*
     * ע�� (1<<n)-1������ʹ���������������n=wʱʧЧ
     * �������Կ���ȫ��1��unsigned��������ɡ�
     * ������һ�����ɵķ�����Ҳ����˵����Э����Ϊn=0ʱʧЧ
     * ������ĿҪ��n��[1,w]��
     */
    unsigned x = ~0;
    return x >> ((sizeof(int) << 3) - n);
}

int main()
{
    printf("%#.8x\n", lower_one_mask(1));

    system("pause");
}