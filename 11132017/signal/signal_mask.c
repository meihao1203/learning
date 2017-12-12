#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void sigFunc(int sig,siginfo_t *p,void *p1)
{
	printf("before sleep signum=%d\n",sig);
	sleep(3);
	printf("after sleep signum=%d\n",sig);
}
int main(void)
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sigFunc;
	act.sa_flags = SA_SIGINFO | SA_RESTART ;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	int ret = sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{	
		perror("sigaction");
		exit(-1);
	}
	while(1);
	return 0;
}