//daemon.c 创建守护进程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int   i, fd;
	char  *buf = "This is a daemon\n";
	
	pid = fork(); //第1步
	if (pid < 0)
	{
		printf("Error fork\n");
		exit(1);
	}
	else if (pid > 0)
	{
		exit(0); //父进程退出 
	}
		
	setsid();//第2步
	
	chdir("/"); //第3步
	
	umask(0); //第4步
	
	for(i = 0; i < getdtablesize(); i++) //第5步 
	{
		close(i);
	}
	
	while(1)
	{
		if ((fd = open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND, 0600)) < 0)
		{
			printf("Open file error\n");
			exit(1);
		}
		
		write(fd, buf, strlen(buf) + 1);
		close(fd);
		sleep(3);
	}
	
	exit(0);
}
