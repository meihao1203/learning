#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void sig_func(int sig)
{
	printf("sig=%d is coming\n",sig);
}
int main(void)
{
	if( signal(SIGINT,SIG_IGN)==SIG_ERR )
	{
		perror("signal");
		exit(-1);
	}
	if( signal(SIGQUIT,sig_func)==SIG_ERR )
	{
		perror("signal");
		exit(-1);
	}
	while(1);
	return 0;
}