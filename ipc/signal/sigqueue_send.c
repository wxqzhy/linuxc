#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char **argv)
{
	union sigval mysigval;
	int iPid,iSignNo,iData;
	if(argc<4)
	{
		printf("usage:pid signnum data");
		return -1;
	}
	iPid=atoi(argv[1]);
	iSignNo=atoi(argv[2]);
	iData=atoi(argv[3]);
	mysigval.sival_int=iData;
	if(sigqueue(iPid,iSignNo,mysigval)<0)
		perror("Send signal fail\n");
	return 0;
}
