//gcc提供__int128来容纳128位整数
//https://gcc.gnu.org/onlinedocs/gcc/_005f_005fint128.html#g_t_005f_005fint128

//int64_t在头文件stdint.h中

#include <stdint.h>
typedef __int128 int128_t;

//汇编指令
/*
方法一：
记x的高32位为HX,低32位为LX;对应的y的高32位为HY,低32位位LY
则x * y = (HX*2^32 + LX)*(HY*2^32 + LY)
		=HX*HY*2^64 + (HX*LY + HY*LX)*2^32 + LX*LY
也就是128位结果分成三部分64位相加的形式

方法二(与方法一类似，只是先进行扩展操作)：
（见csapp的2.4.5（第三版）的补码乘法）
先将x,y符号扩展成128位，然后乘法截取其128位即可（这个在补码乘法部分介绍过）
（这段代码使用了这个方法）


store_prod
	movq	%rdx, %rax      #%rax保存y
	cqto                    #直接将 %rax中的符号位并将其复制到 %rdx的所有位中
                            #从而将%rax扩展成%rdx:%rax（此时y扩展成%rdx:%rax）
	movq	%rsi, %rcx      #%rcx保存x
	sarq	$63, %rcx		#把x符号扩展成%rcx:%rsi，x是128位的

	#此时y表示为rdx:rax,x表示为rcx:rsi, 
	即y = rdx*2^64 + rax, x = rcx*2^64 + rsi

	#x*y = %rdx*%rcx*2^128 + %rdx*%rsi*2^64 + %rcx*%rax*2^64 + %rax*%rsi
	#由于我们只需要取低128位，所以对x*y进行取模操作mod 128，
	得到公式：rdx*rsi*2^64mod2^128 + rcx*rax*2^64mod2^128 + rax*rsi

	#（利用特性）由于这里的寄存器都是64位的，
	所以对于rdx*rsi*2^64mod2^128这样的操作我们可以直接使用imulq指令，
	截取两个寄存器相乘的低64位，然后把他加到rax*rsi的高64位。

	******下面是具体操作
	imulq	%rax, %rcx
	imulq	%rsi, %rdx
	addq	%rdx, %rcx		#前三个指令是计算出()*2^64中的数据(结果的高64位)
	mulq	%rsi			#计算结果的低64位,高64位被放入%rdx
	addq	%rcx, %rdx		#这步相加是把XL*YL的高64位与()*2^64的低64位相加
							#而()*2^64的高64位被取模取掉了
	movq	%rax, (%rdi)	#存放低64位
	movq	%rdx, 8(%rdi)	#存放高64位
	ret

*/

void store_prod(int128_t *dest, int64_t x, int64_t y)
{
	*dest = x * (int128_t)y;
}

//用gcc -Og -S 59.cpp生成的汇编在同一目录下
//与书上的汇编存在差异
