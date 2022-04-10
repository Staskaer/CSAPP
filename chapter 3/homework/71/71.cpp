#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*没看懂题目，抄的T_T*/
#define SIZE_OF_BUFFER 10

int good_echo(void)
{
    char *buffer = (char *)calloc(SIZE_OF_BUFFER, sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: failed to allocate buffer.\n");
        return -1;
    }
    while (1)
    {
        fgets(buffer, SIZE_OF_BUFFER, stdin);
        if (strlen(buffer) == SIZE_OF_BUFFER - 1)
        /*两种情况，一种是刚好输入了能填满缓冲区的字符数，另一种是大于缓冲区，一次不能读完*/
        {
            fputs(buffer, stdout);
            if (buffer[SIZE_OF_BUFFER - 1 - 1] == '\n')
            /*刚好输入了能填满缓冲区的字符数,结束读入*/
            {
                break;
            }
            memset(buffer, 0, strlen(buffer));
            /*清空缓冲区，因为要通过strlen判断读入了多少字符，继续读入*/
        }
        else if (strlen(buffer) < SIZE_OF_BUFFER - 1)
        /*一定是最后一次读入，结束读入*/
        {
            fputs(buffer, stdout);
            break;
        }
        else
        {
            break;
        }
    }
    free(buffer);
    return 0;
}

int main(int argc, char const *argv[])
{
    return good_echo();
}
