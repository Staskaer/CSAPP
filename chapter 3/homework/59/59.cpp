//gcc�ṩ__int128������128λ����
//https://gcc.gnu.org/onlinedocs/gcc/_005f_005fint128.html#g_t_005f_005fint128

//int64_t��ͷ�ļ�stdint.h��

#include <stdint.h>
typedef __int128 int128_t;

//���ָ��
/*
����һ��
��x�ĸ�32λΪHX,��32λΪLX;��Ӧ��y�ĸ�32λΪHY,��32λλLY
��x * y = (HX*2^32 + LX)*(HY*2^32 + LY)
		=HX*HY*2^64 + (HX*LY + HY*LX)*2^32 + LX*LY
Ҳ����128λ����ֳ�������64λ��ӵ���ʽ

������(�뷽��һ���ƣ�ֻ���Ƚ�����չ����)��
����csapp��2.4.5�������棩�Ĳ���˷���
�Ƚ�x,y������չ��128λ��Ȼ��˷���ȡ��128λ���ɣ�����ڲ���˷����ֽ��ܹ���
����δ���ʹ�������������


store_prod
	movq	%rdx, %rax      #%rax����y
	cqto                    #ֱ�ӽ� %rax�еķ���λ�����临�Ƶ� %rdx������λ��
                            #�Ӷ���%rax��չ��%rdx:%rax����ʱy��չ��%rdx:%rax��
	movq	%rsi, %rcx      #%rcx����x
	sarq	$63, %rcx		#��x������չ��%rcx:%rsi��x��128λ��

	#��ʱy��ʾΪrdx:rax,x��ʾΪrcx:rsi, 
	��y = rdx*2^64 + rax, x = rcx*2^64 + rsi

	#x*y = %rdx*%rcx*2^128 + %rdx*%rsi*2^64 + %rcx*%rax*2^64 + %rax*%rsi
	#��������ֻ��Ҫȡ��128λ�����Զ�x*y����ȡģ����mod 128��
	�õ���ʽ��rdx*rsi*2^64mod2^128 + rcx*rax*2^64mod2^128 + rax*rsi

	#���������ԣ���������ļĴ�������64λ�ģ�
	���Զ���rdx*rsi*2^64mod2^128�����Ĳ������ǿ���ֱ��ʹ��imulqָ�
	��ȡ�����Ĵ�����˵ĵ�64λ��Ȼ������ӵ�rax*rsi�ĸ�64λ��

	******�����Ǿ������
	imulq	%rax, %rcx
	imulq	%rsi, %rdx
	addq	%rdx, %rcx		#ǰ����ָ���Ǽ����()*2^64�е�����(����ĸ�64λ)
	mulq	%rsi			#�������ĵ�64λ,��64λ������%rdx
	addq	%rcx, %rdx		#�ⲽ����ǰ�XL*YL�ĸ�64λ��()*2^64�ĵ�64λ���
							#��()*2^64�ĸ�64λ��ȡģȡ����
	movq	%rax, (%rdi)	#��ŵ�64λ
	movq	%rdx, 8(%rdi)	#��Ÿ�64λ
	ret

*/

void store_prod(int128_t *dest, int64_t x, int64_t y)
{
	*dest = x * (int128_t)y;
}

//��gcc -Og -S 59.cpp���ɵĻ����ͬһĿ¼��
//�����ϵĻ����ڲ���
