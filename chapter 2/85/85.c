/*
 * ��85�⣺���������ʽ����kλָ����nλС��������������
 * д������E��β��M��С��f����ֵV�Ĺ�ʽ
 * 1. 7.0
 * 2. �ܹ���׼ȷ�������������
 * 3. ��С�ĸ�ʽ�����ĵ���
*/

/*
 * ���
 * 1. 
 * ƫ��bias = 2^(k-1) - 1
 * ֵV = 2^E * M
 * 7.0 = 111.000 = 1.11 << 2
 * ����E = 2 = e - bias ---> e = E + bias = 1 + 2^(k-1)
 * β��M = 1 + f = 1 + 0.11
 * 
 * 2.
 * �ܹ�������������������λӦ����111111......
 * ����������ʾΪ1.111111...*2^n����ʽ��С������Ӧ����n��1 �õ���Щ�����Ǿ��ܼ�����ø������Ķ����Ʊ�ʾ
 * �������������λ11111... ��n+1��1 Ҳ����2^(n+1) - 1
 * E = n  ==> e = E + bias = n + bias
 * ==> 0 n + bias 11111...
 * 
 * 3.
 * ��С�Ĺ������С��Ϊ0x0������Ϊ0x1-bias
 * ����V = 2^(1-bias)*1    -> ����Ϊ 2^(bias - 1)
*/