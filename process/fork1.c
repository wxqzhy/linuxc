#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	printf("hhhhhhh\n");
	int count=0;
	pid=fork();
	printf("hello\n");
	if(pid<0) 
		printf("error in fork\n");
	else if(pid==0)
	{
		printf("I am the chilid process:%d %d\n",getpid(),getppid());
	}
	else
		printf("I am the parent process:%d\n",getpid());
	count++;
	printf("count=%d\n",count);
	return 0;
}
