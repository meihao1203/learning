#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
void sigFunc(int sig,siginfo_t *p,void *p1)
{
	printf("I am sig %d\n",sig);
	printf("si_pid=%d si_uid=%d\n",p->si_pid , p->si_uid);
}
int main(void)
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sigFunc;
	act.sa_flags = SA_SIGINFO;
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