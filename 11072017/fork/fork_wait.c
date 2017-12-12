#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		sleep(5);
		printf("I am son , pid=%d ppid=%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("I am father , pid=%d ppid=%d\n",getpid(),getppid());
		wait(NULL);
		printf("I am wake\n");
		exit(0);
	}
	return 0;
}