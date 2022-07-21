#ifdef COMPILETIME

#include <malloc.h>
#include <stdio.h>

void *mymalloc(size_t size)
{
    void *ptr = malloc(size);
    printf("malloc\n");
    return ptr;
}

void myfree(void *ptr)
{
    free(ptr);
    printf("free!");
}

#endif

#ifdef LINKTIME

#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size)
{
    void *ptr = __real_malloc(size);
    printf("malloc\n");
    return ptr;
}

void __wrap_free(void *ptr)
{
    __real_free(ptr);
    printf("free!");
}

#endif