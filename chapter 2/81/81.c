/*
 * ��81�⣺��дc���ʽ��a^k�������a�ظ�k��
 * ʵ�֣�����һ��wλ�����ݣ�������԰����Բ���j��k�����ã�
 * �ֱ��ʾj��k��ֵ�����ǲ���ʹ�ñ�ʾw�Ĳ���
 * 1. 1^(w-k)0^k
 * 2. 0^(w-k-j)1^k0^j
*/

#include <stdio.h>
#include <stdlib.h>

int generate(int j, int k)
{
    /*
     * ��һ���ܼ�
     * �ڶ���ʵ�����ڵ�һ�����ɵĻ�����������һ����ģ
    */

    unsigned first, second;
    first = ~((1 << k) - 1);
    second = ((1 << (k + j)) - 1) & ~((1 << j) - 1);

    printf("1. %#.8x\n", first);
    printf("2. %#.8x\n", second);

    return 0;
}

int main()
{
    generate(8, 16);

    system("pause");
}