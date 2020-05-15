#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	printf("PID=%d\n",getpid());
	pid = fork();
	if(pid > 0)
	{
		printf("parent PID=%d\n",getpid());
		printf("parent PGID=%d\n",getpgrp());
		sleep(1);
	}
	if(pid == 0)
	{
		printf("child PID=%d\n",getpid());
		printf("child PPID=%d\n",getppid());
		printf("child PGID=%d\n",getpgrp());
	}
	
	return 0;
}
