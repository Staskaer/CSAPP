#include "csapp.h"

void handler_bad(int sig)
//不正确的信号处理函数，因为基于了信号会排队的假设
{
    int olderrno = errno;
    if ((waitpid(-1, NULL, 0)) < 0)
        unix_error("waipid error\n");
    printf("handler reaped child \n");
    Sleep(1);
    errno = olderrno;
}

void handler_good(int sig)
//正确的信号处理函数
{
    int olderrno = errno;
    while ((waitpid(-1, NULL, 0)) > 0)
        printf("handler reaped child \n");
    if (errno != ECHILD)
        unix_error("waipid error\n");
    Sleep(1);
    errno = olderrno;
}

int main()
{
    int i, n;
    char buf[MAXBUF];

//选择不同的信号处理函数来查看效果
#ifndef GOOD
    if (signal(SIGCHLD, handler_bad) == SIG_ERR)
        unix_error("signal err!\n");
#else
    if (signal(SIGCHLD, handler_good) == SIG_ERR)
        unix_error("signal err!\n");
#endif

    for (int i = 0; i < 3; i++)
        if (Fork() == 0)
        {
            printf("child %d\n", (int)getpid());
            exit(0);
        }

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
        unix_error("read");
    printf("parent process input!\n");
    while (1)
        ;
    exit(0);
}