#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid; 
	int count=0;
	pid=vfork();  //注意与fork的区别
	printf("hello\n");
	if(pid==0){
		printf("I am the chilid process\n" );
		count++;
		_exit(0);
		}
	else{
		sleep(1);
		printf("I am the parent process\n");
		count++;}
	printf("count=%d\n",count);
	return 0;
}
