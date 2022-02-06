/*
 * ��76�⣺��д����void *calloc(size_t nmemb,size_t size)
 * ͨ��malloc�����ڴ棬����memset���ڴ�����Ϊ0
 * ȷ�����벻�����κ����������©��
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ano_calloc(size_t nmemb, size_t size)
{
    void *pt;

    if (nmemb == 0 || size == 0)
        return NULL;
    size_t buff_size = nmemb * size;
    if ((size_t)(buff_size / size) == nmemb)
    {
        pt = malloc(buff_size);
        memset(pt, 0, buff_size);
        return pt;
    }
    return NULL;
}

int main()
{
    void *p;
    p = ano_calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = ano_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);

    system("pause");
    return 0;
}