#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;
//定义线程函数
void * thread(void * arg)
{
    int i=0;
    while(i<50000)
    {
        i++;
        int tmp=count;
        count = tmp + 1;
    }
}
int main(void)
{
    pthread_t id1,id2;
	
    pthread_create(&id1,NULL,(void *) thread,NULL);
    pthread_create(&id2,NULL,(void *) thread,NULL);
    
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);

    printf("count=%d\n",count);
	return (0);
}
