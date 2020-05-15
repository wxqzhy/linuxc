#include <time.h>
#include <stdio.h>

int main()
{
	struct tm *local;
	time_t t;
	t=time(NULL);
	printf("%ld\n",t);
	time(&t);
	printf("%ld\n",t);
	local=localtime(&t);
	printf("Local hour is:%d\n",local->tm_hour);
	local=gmtime(&t);
	printf("UTC hour is:%d\n",local->tm_hour);
}
