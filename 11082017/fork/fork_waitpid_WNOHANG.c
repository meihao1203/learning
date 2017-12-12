#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();
	if( 0==pid )
	{
		//sleep(5);
		printf("I am child , my pid =%d ppid =%d\n",getpid(),getppid());
		exit(0);
	}
	else 
	{
		printf("I am father , my pid =%d ppid =%d\n",getpid(),getppid());
		int status;
		//printf("sleep\n");
		//sleep(10);
		printf("sleep over\n");
		//printf("no sleep\n");
		waitpid(pid,&status,WNOHANG);
		printf("I am wake\n");
		if( WIFEXITED(status) )
		{
			printf("child terminated normally , exited value %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("child terminated abnormally , exited value %d\n",WEXITSTATUS(status));
		}
		exit(0);
	}
	return 0;
}