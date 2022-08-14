#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int mysystem(char *cmd)
{
    pid_t pid;
    int status;

    if ((pid = fork()) == 0)
    {
        //子进程执行/bin/sh -c command命令
        //关于exec函数组的用法可以参见 https://blog.csdn.net/lqy971966/article/details/110532621
        execl("/bin/sh", "sh", "-c", cmd, NULL);
    }
    else
    {
        //父进程处理子进程的执行状态
        if (waitpid(pid, &status, 0) == pid)
        {
            //完成子进程的回收
            if (WIFEXITED(status))
            {
                //如果退出，则返回退出的状态
                return WEXITSTATUS(status);
            }
            else if (WIFSIGNALED(status))
            {
                //否则如果为异常终止，返回shell状态
                fprintf(stderr, "command terminated by signal number %d.\n", WTERMSIG(status));
                if (WCOREDUMP(status))
                {
                    fprintf(stderr, "core dumped...\n");
                }
                return WTERMSIG(status);
            }
            else
            {
                //其他情况的异常终止，返回状态
                fprintf(stderr, "command terminated abnormally.\n");
                fprintf(stderr, "return status information...\n");
                return status;
            }
        }
        else
        {
            //如果waitpid返回了其他值，则说明子进程没有启动
            fprintf(stderr, "Failed to reap /bin/sh.\n");
            return 1;
        }
    }
}

int main(int argc, char *argv[], char **envs)
{
    mysystem("echo 1");
}