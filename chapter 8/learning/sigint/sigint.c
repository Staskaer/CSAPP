#include "csapp.h"

void sigint_handler(int sig)
{
    printf("\nsigint !\n");
    exit(0);
}

int main()
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("singal error");
    pause();
    return 0;
}