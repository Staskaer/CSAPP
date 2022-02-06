/*
 * 第70题：写出具有如下原型的函数 int fits_bits(int x,int n)
 * 实现当x能够被表示成n位2进制就返回1，否则返回0
 * n [1,w]
*/

#include <stdio.h>
#include <stdlib.h>

int fits_bits(int x, int n)
{
    /*
     * 判断能不能存储，只要看x的前w-n+1位是否全是1（负）
     * 或x的前w-n位是否全是0（正）
     * （负数多一位才能判断）如0b11111000,0b11111100前者不能，后者可以
     * 先右移n-1位，因为是int，所以是算数右移
     * 如果是负数且能存储，则剩下的全是1，不能存储则会出现0
     * 如果是正数且能存储，则剩下的全是0，不能存储则会出现1
    */

    x = x >> (n - 1);

    return !(x >> 1) | !~x;
}

int main()
{
    printf("%d", fits_bits(0xff, 7));

    system("pause");
}