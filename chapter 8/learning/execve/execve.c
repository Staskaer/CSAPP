#include "eval.h"
int main()
{

    char cmdline[MAXARGS];
    while (1)
    {
        printf(" >");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);
        eval(cmdline);
    }
}