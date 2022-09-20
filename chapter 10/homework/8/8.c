#include "csapp.c"
#include "csapp.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    // 没看懂题目的意思，照搬了一个

    struct stat stat;
    char *type, *readok;
    char buf[MAXBUF];
    char filename[MAXBUF];
    memset(buf, 0, MAXBUF);
    memset(filename, 0, MAXBUF);

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <descriptor number>\n", argv[0]);
        exit(0);
    }

    sprintf(buf + sprintf(buf, "/proc/self/fd/"), argv[1]);

    if (readlink(buf, filename, sizeof(filename)) == -1)
    {
        fprintf(stderr, "bad file descriptor\n");
        exit(EXIT_FAILURE);
    }

    Stat(filename, &stat);
    if (S_ISREG(stat.st_mode)) /* Determine file type */
        type = "regular";
    else if (S_ISDIR(stat.st_mode))
        type = "directory";
    else
        type = "other";
    if ((stat.st_mode & S_IRUSR)) /* Check read access */
        readok = "yes";
    else
        readok = "no";

    printf("type: %s, read: %s\n", type, readok);
    exit(0);
}