/*
 * ��72�⣺��д������������val���Ƶ�������buf�У�
 * ����ֻ�е����������㹻���ÿռ�ʱ��ִ�и���
 * ����������룬��maxbytes��СʱҲ�ܸ��Ƶ�������
 * 
 * ����Ϊʲô������
 * ����
*/

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//�������
void bad_copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));

    /*
         * ����ԭ��sizeof��������ʱunsigned
         * ����int������ʱ�ᱻ������unsigned��ʼ�մ���0����������
        */
}

//��������
void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - (int)sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}
int main()
{
    system("color 1a");
    system("pause");
}