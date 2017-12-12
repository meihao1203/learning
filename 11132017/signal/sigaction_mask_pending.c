#include<signal.h>
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
void sigFunc(int sig,siginfo_t *p,void *p1)
{
	printf("before signum=%d\n",sig);
	sleep(3);
	sigset_t set;
	sigemptyset(&set);
	sigpending(&set);
	if( sigismember(&set,SIGQUIT) )
	{
		printf("SIGQUIT is come , but pending\n");
	}
	else 
	{
		printf("SIGQUIT is not come\n");
	}
	printf("after signum=%d\n",sig);
}
int main(void)
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_sigaction = sigFunc;
	int ret = sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		exit(-1);
	}
	while(1);
	return 0;
}
