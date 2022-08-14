#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define TIMEOUT ((unsigned int)5)
#define SIZEOFBUF 1024

jmp_buf buf;

void SIGALRM_handler(int signum)
{
    longjmp(buf, 1);
}

char *tfgets(char *s, int size, FILE *stream)
{
    if (signal(SIGALRM, SIGALRM_handler) == SIG_ERR)
    {

        perror("Failed to install SIGALRM_handler");
        return NULL;
    }
    else
    {
        alarm(TIMEOUT); /* raise SIGALRM after TIMEOUT seconds */
    }

    if (!setjmp(buf))
    //当时间未到时，不会发生跳转，否则发生跳转，并执行到else中
    {
        return fgets(s, size, stream);
    }
    else /* longjmp from SIGALRM_handler */
    {
        return NULL;
    }
}

int main(int argc, char const *argv[])
{
    char temp_bufer[SIZEOFBUF];
    char *result = tfgets(temp_bufer, SIZEOFBUF, stdin);

    if (result)
    {
        printf("Input : %s\n", result);
    }
    else
    {
        fprintf(stderr, "Time out!\n");
    }

    return 0;
}