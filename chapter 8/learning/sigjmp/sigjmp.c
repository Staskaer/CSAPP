#include "csapp.h"

sigjmp_buf buf;
int c=0;

void handler(int sig)
{
	if(++c>10)
		exit(0);
	siglongjmp(buf,1);
}

int main()
{
	if(!sigsetjmp(buf,1))
	{
		Signal(SIGINT,handler);
		printf("starting!\n");
	}
	else
		printf("\nrestrating!\n");
	
	while(1)
	{
		Sleep(1);
		printf("processing...\n");
	}
	exit(0);
}
