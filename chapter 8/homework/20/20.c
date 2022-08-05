#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[], const char *envp[])
{
    if (execve("/bin/ls", argv, envp))
    {
        perror("Failed to execve /bin/ls:\n");
    }
    return 0;
}