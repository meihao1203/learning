#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void sigFunc(int sig,siginfo_t *p,void *p1)
{
	printf("before sleep , signum=%d\n",sig);
	sleep(3);
	printf("after sleep , signum=%d\n",sig);
}
int main(void)
{
	sigset_t set;
	memset(&set,0,sizeof(set));
	sigaddset(&set,SIGINT);
	int ret = sigprocmask(SIG_BLOCK,&set,NULL);
	if(-1==ret)
	{
		perror("sigprocmask");
		exit(-1);
	}
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sigFunc;
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act.sa_mask);
	ret = sigaction(SIGINT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction");
		exit(-1);
	}
	//while(1);
	sleep(5);
	printf("\nafter sleep , unblock SIG_INT\n");
	sigprocmask(SIG_UNBLOCK,&set,NULL);
	while(1);
	return 0;
}