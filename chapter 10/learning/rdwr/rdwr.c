#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char c;

    while (read(STDIN_FILENO, &c, 1) != 0)
        write(STDOUT_FILENO, &c, 1);

    // 读取输入流中的字符并输出出去。

    return 0;
}