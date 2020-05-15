#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pc,pr;
	pc=fork();
	if(pc==0)
	{
		printf("This is child process with pid of chilid:%d\n",getpid());
		sleep(10);
	}
	else if(pc>0)
	{
		printf("wait\n");
		pr=wait(NULL);
		printf("I catched a child process with pid of %d\n",pr);
	}
	exit(0);
}
