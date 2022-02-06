/*
 * 第81题：编写c表达式，a^k代表符号a重复k次
 * 实现：假设一个w位的数据，代码可以包含对参数j、k的引用，
 * 分别表示j、k的值，但是不能使用表示w的参数
 * 1. 1^(w-k)0^k
 * 2. 0^(w-k-j)1^k0^j
*/

#include <stdio.h>
#include <stdlib.h>

int generate(int j, int k)
{
    /*
     * 第一个很简单
     * 第二个实际是在第一个生成的基础上再增加一层掩模
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