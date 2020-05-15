#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <sys/wait.h>

int main()
{
	int pipe_fd[2];
	pid_t pid;
	char buf_r[100];
	char* p_wbuf;
	int r_num;

	memset(buf_r,0,sizeof(buf_r));
	
	if(pipe(pipe_fd)<0)
	{
		printf("pipe create error\n");
		return -1;
	}
	if((pid=fork())==0)
	{
		printf("\n");
		close(pipe_fd[1]);//关闭写管道
		sleep(2);	  //等待父进程写管道
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
		{
			printf("%d numbers read from the pipe is %s \n",r_num,buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	}
	else if(pid>0)
	{
		close(pipe_fd[0]);//关闭读管道
		if(write(pipe_fd[1],"Hello",5)!=-1)
			printf("Parent write Hello\n");
		if(write(pipe_fd[1]," Pipe",5)!=-1)
			printf("Parent write Pipe\n");
		close(pipe_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0);//等待子进程结束
		exit(0);
	}
}
