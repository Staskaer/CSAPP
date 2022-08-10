#include "csapp.h"

volatile sig_atomic_t pid;
int num = 0;

void sigchld_handler(int s)
{
	int olderrno = errno;
	pid = waitpid(-1, NULL, 0);
	errno = olderrno;
}

void sigint_handler(int s)
{
	num++;
	if (num > 5)
	{
		printf("sigint\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	sigset_t mask, prev;
	Signal(SIGCHLD, sigchld_handler);
	Signal(SIGINT, sigint_handler);
	Sigemptyset(&mask);
	Sigaddset(&mask, SIGCHLD);

	while (1)
	{
		Sigprocmask(SIG_BLOCK, &mask, &prev);
		if (Fork() == 0)
			exit(0);

		pid = 0;
		while (!pid)
			sigsuspend(&prev);

		Sigprocmask(SIG_BLOCK, &mask, &prev);

		printf(".");
	}
	exit(0);
}
