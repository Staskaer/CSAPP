/*
 * ��55�⣺
 * �����ܹ����ʵĲ�ͬ�����ϣ�ʹ��show_bytes
 * ���벢������ȷ��ʹ�û������ֽ�˳��
 * 
 * ��56�⣺�����ò�ͬ��ֵ������show_byte
 * 
 * ��57�⣺��дshow_short,show_long,show_double�Ĵ���
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    /*
     * �˺����������ǽ������ָ��������͵�ָ�뿴��unsigned char����
     * ����������������һ�㶼��char���ͳ��ȵ�������
     * ���Կ��Խ��������Ͱ���ռ��λ���ֽ�ɶ��char����ӡ����
     * 
     * ʵ������ʹ��ǿ������ת������ܻ�������
    */
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    printf("show_int function, sizeof(int) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * ��int������ǿ��ת����char���鲢��λ���
    */
}

void show_float(float x)
{
    printf("show_float function, sizeof(float) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * ��float������ǿ��ת����char���鲢��λ���
    */
}

void show_pointer(void *x)
{
    printf("show_pointer function, sizeof(void *) is %d\n", (int)sizeof(void *));

    show_bytes((byte_pointer)&x, sizeof(void *));
    /*
     * ��void *������ǿ��ת����char���鲢��λ���
    */
}

void show_short(short x)
{
    printf("show_short function, sizeof(short) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * ��short������ǿ��ת����char���鲢��λ���
    */
}

void show_long(long x)
{
    printf("show_long function, sizeof(long) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * ��long������ǿ��ת����char���鲢��λ���
    */
}

void show_double(double x)
{
    printf("show_double function, sizeof(double) is %d\n", (int)sizeof(x));

    show_bytes((byte_pointer)&x, sizeof(x));
    /*
     * ��double������ǿ��ת����char���鲢��λ���
    */
}

int main()
{
    short val = 1;

    show_int((int)val);
    show_float((float)val);
    show_pointer((void *)&val);
    show_short((short)val);
    show_long((long)val);
    show_double((double)val);

    system("pause");

    return 0;
}
/*
 * ��ʹ�õĻ�����64λWindows��
 * �۲�����С�˷�����
 * ����int 4λ��float 4λ��ָ��8λ
*/