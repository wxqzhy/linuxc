#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO "/tmp/myfifo"

int main(int argc,char** argv)
{
	char buf_r[100];
	int fd;
	int nread;
	//create fifo pipe
	//判断fifo管道是否已经存在，若未创建则以相应的权限创建
	if(access(FIFO,F_OK)==-1)
	{
		if((mkfifo(FIFO,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
		{
			printf("cannot create fifoserver\n");
			exit(-1);
		}
	}
	printf("Preparing for reading bytes...\n");
	
	//fd=open(FIFO,O_RDONLY|O_NONBLOCK,0);
	
	fd=open(FIFO,O_RDONLY,0);
	if(fd==-1)
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		memset(buf_r,0,sizeof(buf_r));
		if((nread=read(fd,buf_r,100))==-1)
		{
			if(errno==EAGAIN)
			{
				printf("no data yet\n");
				break;	
			}
		}
		else if(nread>0)
		{
			printf("read from FIFO:%s\n",buf_r);
		}
		sleep(1);
	}
	pause();
	unlink(FIFO);//delete FIFO
}
