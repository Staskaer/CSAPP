#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 5

int main()
{
    int status;
    pid_t pid;

    for (int i = 0; i < N; i++)
    {
        if (((pid = fork()) == 0))
        {
            //子进程通过对NULL解引用来实现异常
            int *p = 0;
            *p = 0;

            return 0;
        }
    }

    while ((pid = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));
        }

        else if (WIFSIGNALED(status))
        {
            fprintf(stderr, "child %d terminated by signal %d", pid, WTERMSIG(status));
            psignal(WTERMSIG(status), " ");
        }

        else
        {
            fprintf(stderr, "child %d terminated abnormally with status information=%d\n", pid, status);
        }
    }

    if (errno != ECHILD)
    {
        fprintf(stderr, "waitpid error");
    }

    return 0;
}