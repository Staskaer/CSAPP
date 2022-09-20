#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    struct stat filestat;
    char *type, *readok;

    // 读取一个文件的元数据
    stat("metadatafile", &filestat);

    // 处理元数据
    if (S_ISREG(filestat.st_mode))
        type = "regular";
    else if (S_ISDIR(filestat.st_mode))
        type = "dir";
    else
        type = "other";
    if ((filestat.st_mode & S_IRUSR))
        readok = "yes";
    else
        readok = "no";
    printf("type %s, read %s \n", type, readok);
}
