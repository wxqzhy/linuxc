#include <stdio.h>
int sum(int num)
{
	int i, result=0;
	for(i=1;i<=num;i++)
		result+=num;
	printf("sum function %d\n",result);
	return result;
}
int main()
{
	int sum1=0;
	int i=0;
	sum(100);
	for(i=1;i<=50;i++)
		sum1+=i;
	printf("main function %d",sum1);
	return 0;
}
