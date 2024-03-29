#include "csapp.h"
#define N 5
int main()
{
    int status, i;
    pid_t pid;
    for (i = 0; i < N; i++)
        if ((pid = Fork()) == 0)
            exit(100 + i);
    while ((pid = waitpid(-1, &status, 0)) > 0)
    {
        if (WIFEXITED(status))
            printf("child %d exit %d\n", pid, WEXITSTATUS(status));
        else
            printf("child %d \n", pid);
    }

    if (errno != ECHILD)
        unix_error("waitpid error");
    exit(0);
}