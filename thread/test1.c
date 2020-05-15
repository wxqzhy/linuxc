#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;
pthread_mutex_t mutex;

//定义线程函数
void * thread(void * arg)
{
    int i=0;
    pthread_mutex_lock(&mutex);
    while(i<50000)
    {
        i++;
        int tmp=count;
        count = tmp + 1;
    }
    pthread_mutex_unlock(&mutex);
}
int main(void)
{
    pthread_t id1,id2;
	pthread_mutex_init(&mutex, NULL);
    pthread_create(&id1,NULL,(void *) thread,NULL);
    pthread_create(&id2,NULL,(void *) thread,NULL);
    
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    pthread_mutex_destroy(&mutex);
    printf("count=%d\n",count);
	return (0);
}
