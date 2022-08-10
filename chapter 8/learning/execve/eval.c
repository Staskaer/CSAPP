#include "eval.h"

void eval(char *cmdline)
{
    char *argv[MAXARGS]; //参数列表
    char buf[MAXARGS];   //保存修改的命令部分
    int bg;              //前后台运行标志位
    pid_t pid;           //进程pid

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return; //忽略空行

    if (!builtin_command(argv)) //非内置命令就执行可执行文件，内置命令只有quit
    {
        if ((pid = Fork()) == 0) //子进程
            if (execve(argv[0], argv, environ) < 0)
            {
                printf("%s:command not found!\n", argv[0]);
                exit(0);
            }

        if (!bg) //父进程，后台执行就等待进程结束
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg:waitpid error");
        }
        else
            printf("%d %s", pid, cmdline);
    }
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);

    if (!strcmp(argv[0], "&")) //忽略掉单行&
        exit(0);

    return 0;
}

int parseline(char *buf, char **argv)
{
    char *delim; //第一个空格分隔符的位置
    int argc;    //参数个数
    int bg;      //前后台执行标志位

    buf[strlen(buf) - 1] = ' '; //替换\n为空格

    while (*buf && *buf == ' ') //忽略掉起始空行
        buf++;

    argc = 0;
    while ((delim = strchr(buf, ' ')))
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++; //忽略空行
    }

    argv[argc] = NULL;
    if (argc == 0)
        return 1; //忽略空行

    if ((bg = (*argv[argc - 1] == '&')) != 0) //前后台执行
        argv[--argc] = NULL;
    return bg;
}