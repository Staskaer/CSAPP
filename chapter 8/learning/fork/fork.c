#include "csapp.h"

int main()
{
    pid_t pid;
    int x = 1;

    Fork();
    Fork();
    pid = Fork();
    if (pid == 0)
    {
        //child
        printf("this is in the child and x = %d\n", --x);
        exit(0);
    }
    else
    {
        //parent
        printf("this is in the parent and x = %d\n", ++x);
        exit(0);
    }
}