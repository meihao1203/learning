#include<stdio.h>
#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void sigFunc(int sig,siginfo_t *p,void *p1)
{
	printf("signal %d is coming\n",sig);
}
int main(void)
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sigFunc;
	act.sa_flags = SA_SIGINFO;
 	int ret = sigaction(SIGINT,&act,NULL);
	if( -1==ret )
	{
		perror("sigaction");
		exit(-1);
	}
	char buf[128];
	read(STDIN_FILENO,buf,sizeof(buf));
	printf("buf=%s\n",buf);
	return 0;

}