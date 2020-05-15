#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define RUN_TIME 10
//定义线程函数
void * thread(void * arg)
{
	int i;
	for(i=0;i<RUN_TIME;i++)
	{
		printf("This is a pthread.\n");
		 sleep(1);
	}
}
int main(void)
{
	pthread_t id;
	int i,ret;
	//创建线程
        ret=pthread_create(&id,NULL,(void *) thread,NULL);
        if(ret!=0){
		printf ("Create pthread error!\n");
		exit(1);
	}
	for(i=0;i<RUN_TIME;i++)
	{
		
		printf("This is the main process.\n");
		sleep(1);
        }
	//等待线程退出
	pthread_join(id,NULL);
	return (0);
}
