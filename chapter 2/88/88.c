/*
 * ��88�⣺
 * ����������������IEEE�����ʽ��9λ�����ʾ
 * 1.
 * һ������λ
 * k=5������λ��bias=15
 * n=3��С��λ
 * 
 * 2.
 * һ������λ
 * k=4�Ľ���λ��bias=7
 * n=4��С��λ
 * 
 * ���ڸ�����A��ֵ��ת������ӽ���B��ֵ
 * ��+������
*/

/*���������CSDN

ע�⣺����ǹ�񻯵�M = 1 + f �ǹ��M = f

0 10110 101 :
A:
E = 22 - 15 = 7 V = (2^-1 + 2^-3 + 1) * 2^7 = 13 * 2^4
B:
ͨ���۲죬���Ƿ��֣��ȱ���С��λ���䣬����룬������У��ڸı�С��λ
���B�� 0 1110 1010 V = 13 * 2^4


1 00111 110��
A:
E = 7 - 15 = -8 (2^-1 + 2^-2 + 1) * 2^-8 = 7/4 * 2^-8 = -7/2^10
B:
1 0011 1110 ==> M = 1 + 2^-1 + 2^-2 + 2^-3 = 15/8
==> 2^E = (7/2^10) / (15/8)  = 7/15 / 2^7 Լ����2^-1*2^-7 = 2^-8
���ǿ���2^E�ķ�Χ 2^-6 ~ 2^14
�����ϱ߼����2^-8���������Χ�У������Ҫ���������ֵ
�ȴ���С�Ŀ�ʼ�������Ϊ2^-6 ��ô 7/2^10 / 2^-6 = 7 / 16
==> (1/16 + 2/16 + 4/16) ==> (1/16 + 1/8 + 1/4)  ==> (2^-4 + 2^-3 + 2^-2)
���B�� 0 0000 0111


0 00000 101:
A:
E = 1 - 15 = -14  V = (2^-1 + 2^-3) * 2^-14 = 5 * 2^-3 * 2^-14 = 5 * 2^-17 = 5/2^17
����ʹ��101��Ϊβ������ôM = (2^-1 + 2^-3 + 1) = 13 * 2^-3
2^E = V/M = 5/2^17 / (13 * 2^-3) = 5/17 * 2^-17 * 2^3 = 5/17 * 2^-14 ��Ȼ���ڷ�Χ֮��
�ȴ���С�Ŀ�ʼ�������Ϊ2^-6 ��ô 5/2^17 / 2^-6 = 5 * 2^-11 ��ȻB�޷���ʾ���С��ֵ
ȡһ������Ƶ� 0 0000 0000


1 11011 000��
A:
E = 27 - 15 = 12 V = 2^12 ȡ-  ��-2^12
B:
�������ֵ�Ƚϴ���˽���ȡ���ֵ1110 e = 14 E = e - 7 = 14 - 7 = 7 �������ܼ���M����Сֵ
M = 2^12 / 2^7 = 2^5
��ȻM��ֵ�޷���ʾ����˽����������ʹ�� 1111 -oo
1 1111 0000
*/