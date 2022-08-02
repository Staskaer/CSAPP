#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t fpid; //fpid表示fork函数返回的值
    int count = 0;
    fpid = fork();
    if (fpid < 0)
        printf("error in fork!");
    else if (fpid == 0)
    {
        printf("我是子进程,id:%d\n", getpid());
        count++;
    }
    else
    {
        printf("我是父进程,id:%d\n", getpid());
        count++;
    }
    printf("统计结果是:%d\n", count);
    exit(0);
}