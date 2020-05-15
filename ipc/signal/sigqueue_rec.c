#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void SigHandlerNew(int signum,siginfo_t *info,void *myact)
{
	printf("Get:%d,info:%d\n",signum,info->si_int);
}

int main(int argc,char **argv)
{
	struct sigaction act;
	if(argc<2)
	{
		printf("usage:signnum\n");
		return -1;
	}
	printf("my pid is %d\n",getpid());
	sigemptyset(&act.sa_mask);
	act.sa_sigaction=SigHandlerNew;
	act.sa_flags=SA_SIGINFO;
	sigaction(atoi(argv[1]),&act,NULL);
	while(1)
	{
		printf("wait for the signal\n");
		//sleep(2);
		pause();
	}
	return 0;
}
