#include <time.h>
#include <stdio.h>

int main()
{
	struct tm *ptr;
	time_t lt;
	lt=time(NULL);
	ptr=gmtime(&lt);
	printf("%s",asctime(ptr));
	printf("%s",ctime(&lt));
	return 0;
}
