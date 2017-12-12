#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void signal_func(int sig)
{
	printf("sig num =%d\n",sig);
}
int main(void)
{
	if( signal(SIGINT,signal_func)==SIG_ERR )
	{
		perror("signal");
		exit(-1);
	}
	while(1);
	return 0;
}