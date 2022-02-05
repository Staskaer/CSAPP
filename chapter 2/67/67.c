/*
 * ����ʮ���⣺��дint_size_is_32()�ĺ�������intΪ32λ�Ļ�������ʾ1
 * ������ʹ��sizeof�����
 * ����bad_int_size_is_32()���䲻�ܺܺõ���һЩ����������
 * 
 * bad...�����ĸ�����û����ѭc���Թ淶
 * �޸Ĵ��룬ʹ������int����Ϊ32λ�Ļ���������
 * �޸Ĵ��룬ʹ������int����Ϊ16λ�Ļ���������
*/

#include <stdio.h>
#include <stdlib.h>

int bad_int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 32;
    //��warning��left shift count >= width of type [-Wshift-count-overflow]
    return set_msb && !beyond_msb;

    /*
     * �ش�32λ������32λ������δ����� -- undefined
    */
}
int int_size_is_32()
{
    //����������32λ������

    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_16()
{
    //����������16λ������

    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main()
{
    printf("%d,%d", int_size_is_32(), int_size_is_32_16());
    system("pause");
}