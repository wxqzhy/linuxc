#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	//此时仅有一个进程
	pid =fork();
	//此时有两个进程同时运行
	if(pid < 0)
		printf("error in fork");
	else if(pid == 0)
		printf("I am the child process, ID is %d\n",getpid());
	else
		printf("I am the parent process, ID is %d\n",getpid());
}

