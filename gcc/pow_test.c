#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	unsigned int x,y;
	unsigned long long res;
	if((argc<3) || (sscanf(argv[1],"%u",&x)!=1) ||
		 (sscanf(argv[2],"%u",&y))!=1)
	{
		printf("Usage: pow base exponent\n");
		exit(1);
	}
	res=unsgn_pow(x,y);
	printf("%u ^ %u = %u\n",x,y,res);
	exit(0);
}
