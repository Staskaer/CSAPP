#include "csapp.h"

/*
由于windows下有些头文件与linux下不相符，因此这些代码无法在windows下编译
*/

void end(void)
{
    printf("2");
    fflush(stdout);
}

int main()
{
    if (Fork() == 0)
        atexit(end);
    if (Fork() == 0)
    {
        printf("0");
        fflush(stdout);
    }
    else
    {
        printf("1");
        fflush(stdout);
    }
    exit(0);
}