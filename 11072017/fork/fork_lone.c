#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return -1;
	}
	if(pid>0)
	{
		printf("I am father , pid=%d ,ppid=%d\n",getpid(),getppid());
		exit(0);
	}
	if(0==pid)
	{
		printf("I am son , pid=%d ,ppid=%d\n",getpid(),getppid());
	  //exit(0);
	  	while(1);
	}
	return 0;

}