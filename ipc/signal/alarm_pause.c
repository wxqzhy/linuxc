/* alarm_pause.c */
//模拟睡眠5秒钟
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void SignHandler(int iSignNo)
{
	printf("signal:%d\n",iSignNo);
}
int main()
{
	printf("setting alarm\n");
	signal(SIGALRM,SignHandler);
	alarm(5);
	
	printf("before pause()\n");
	pause();
	printf("after pause()\n");
	
	return 0;
}
