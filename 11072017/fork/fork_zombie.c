#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid = fork();
	if( pid==0 )
	{
		printf("I am son , pid=%d ppid=%d",getpid(),getppid());
		exit(0);
	}
	if( pid>0 )
	{
		printf("I am father , pid=%d ppid=%d\n",getpid(),getppid());
		while(1);
	}
	return 0;
}