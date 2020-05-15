#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void SignHandlerNew(int signum,siginfo_t *info,void *myact)
{
	char *pszInfo=(char*)(info->si_ptr);
	printf("Get:%d info:%s\n",signum,pszInfo);
}

int main(int argc,char **argv)
{
	struct sigaction act;
	union sigval mysigval;
	int sig;
	char data[]="other data info";
	if(argc<2)
	{
		printf("usage SIGNNUM\n");
		return -1;
	}
	mysigval.sival_ptr=data;
	sig=atoi(argv[1]);//要发送的信号
	sigemptyset(&act.sa_mask);
	act.sa_sigaction=SignHandlerNew;
	act.sa_flags=SA_SIGINFO; //包含这个选项调用SigHandlerNew
	sigaction(sig,&act,NULL);
	
	while(1)
	{
		printf("wait for the signal\n");
		sigqueue(getpid(),sig,mysigval); //给自己发送信号
		sleep(2);
	}
}
