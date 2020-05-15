/* waitpid.c */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pc, pr;
	pc = fork();
	if (pc < 0)
	{
		printf("Error fork\n");
		exit(1);
	}
	else if (pc == 0)	//child process 
	{ 
		printf("child process:%d\n",getpid());
		sleep(5);
		exit(0);
	}
	else
	{
		do
		{
			pr = waitpid(pc, NULL, WNOHANG);//WNOHANG-- 0
			//Parent process wait child process exit,no stop
			if (pr == 0)
			{
				printf("The child process has not exited\n");
				sleep(1);
			}
		} while (pr == 0);
		
		if (pr == pc)
		{
			printf("Get child exit code: %d\n",pr);
		}
		else
		{
			printf("Some error occured.\n");
		}
	}
	
	return 0;
}
