#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int count=0;
	pid=vfork();
	//wxq 2011.7.28
	
	if(pid==0)
	{
		count++;
		_exit(0);
	}
	else
		count++;
	printf("count=%d\n",count);
	return 0;
}
