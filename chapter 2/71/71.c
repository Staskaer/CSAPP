/*
 * ��71�⣺ʵ�����¹��ܺ���
 * ʹ�ò����������������
 * ������ȡָ�����ֽڣ�Ȼ�����������չΪһ��32λint
 * 
 * ���⣺ˮƽ���ߵĴ��������������
 * ��θ�����ֻʹ������λ�ƺ�һ��������
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned packed_t;

//ˮƽ���ߵĴ���
int bad_xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xff;

    /*
     * �˴�ֻ�Ǽ򵥵Ľ���λ����
     * ȡ�����ֽ��Ǹ�ֵ��������ķ�����ֵ
    */
}

int xbyte(packed_t word, int bytenum)
{
    unsigned left_move = (3 - bytenum) << 3;
    unsigned right_move = 3 << 3;
    return (int)word << left_move >> right_move;

    /*
     * ʹ��������ѡ�񵽱�������λ
     * ʹ�����������������ƶ���ĩβ������չ
    */
}

int main()
{
    printf("%#.8x\n", xbyte(0x8008ff00, 3));
    system("pause");
}