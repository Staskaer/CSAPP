#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main()
{
    struct stat stat_of_file;
    int fd;
    char *p;
    fd = open("hello.txt", O_RDWR); // 读写操作
    fstat(fd, &stat_of_file);       // 获取文件信息
    p = mmap(0, stat_of_file.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
    p[0] = 'J';
}