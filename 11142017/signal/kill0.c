#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{
	if( !fork() )
	{
		printf("I am child\n");
	}
	else
	{
		printf("I am father , begin sleep \n");
		sleep(5);
		int ret = kill(getpid(),SIGINT);
		if(-1==ret)
		{
			perror("kill");
			exit(-1);
		}
		wait(NULL);
		printf("wait is execute\n");
	}
	return 0;
}