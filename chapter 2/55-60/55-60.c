/*
 * ���ļ��漰55-60�⣬��Ϊ56-60����Ҫ�õ�55��ĺ���
 * 
 * ��55�⣺
 * �����ܹ����ʵĲ�ͬ�����ϣ�ʹ��show_bytes
 * ���벢������ȷ��ʹ�û������ֽ�˳��
 * 
 * ��56�⣺�����ò�ͬ��ֵ������show_byte
 * 
 * ��57�⣺��дshow_short,show_long,show_double�Ĵ���
 * 
 * ��58�⣺��д�ܹ���ʾ��ǰ�����Ǵ�˻���С�˵Ļ���
 * 
 * ��59�⣺��дc���Ա��ʽ��������x�����Ч�ֽں�yʣ�µ��ֽ����
 * 
 * ��60�⣺��һ��wλ�����е��ֽڴ�0��w/8-1��š�д��c�������룬�����޷���ֵ
 * ����x���ֽ�i�������ֽ�b
 * ʾ�� replace_byte(0x12345678,2,0xab) --> 0x12ab5678
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

//��55������
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

//��57������
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

//��58������
void is_little_endian()
{
    short val = 1;
    if (((byte_pointer)&val)[0] == 1)
        printf("is little endian\n");
    else
        printf("is not little endian\n");

    //����ǰ�����Ŀ������С�����1��������0����������д
    //������Ϊ�˴���if-else�������������
    //printf("%d", ((byte_pointer)&val)[0]);
}

//��59��
void generate(int x, int y, size_t len_y)
{
    //x,y��һ����int���ͣ���Ҫ����sizeof(y)

    printf("y : ");
    for (size_t i = 0; i < len_y; i++)
        printf("%.2x ", ((byte_pointer)&y)[i]);

    ((byte_pointer)&y)[0] = ((byte_pointer)&x)[0];
    printf("\ny(now) :");
    for (size_t i = 0; i < len_y; i++)
        printf("%.2x ", ((byte_pointer)&y)[i]);
    printf("\n");
}

//��60��
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    //������֪������С�˷����ʱ���ʵ����������������ֱ�ʾ˳��
    printf("\nx : ");
    for (int i = 3; i >= 0; i--)
        printf("%.2x ", ((byte_pointer)&x)[i]);
    ((byte_pointer)&x)[i] = b;
    printf("\nx(now) : ");
    for (int i = 3; i >= 0; i--)
        printf("%.2x ", ((byte_pointer)&x)[i]);
    return x;
}

int main()
{
    //55��-57����Դ���
    short val = 1;

    show_int((int)val);
    show_float((float)val);
    show_pointer((void *)&val);
    show_short((short)val);
    show_long((long)val);
    show_double((double)val);

    //58����Դ���
    is_little_endian();

    //59����Դ���
    int x = 1;
    short y = 1234;
    generate(x, y, sizeof(y));

    //60����Դ���
    replace_byte(0x12345678, 2, 0xab);

    system("pause");

    return 0;
}
/*
 * ��ʹ�õĻ�����64λWindows��
 * �۲�����С�˷�����
 * ����int 4λ��float 4λ��ָ��8λ
*/