#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void func(int sig)
{
	printf("before sleep , sig=%d\n",sig);
	sleep(3);
	printf("after sleep , sig=%d\n",sig);
}
int main(void)
{
	if( signal(SIGINT,func)==SIG_ERR )
	{
		perror("SIGINT");
		exit(-1);
	}
	if( signal(SIGQUIT,func)==SIG_ERR )
	{
		perror("SIGQUIT");
		exit(-1);
	}
	char buf[128];
	memset(buf,0,sizeof(buf));
	read(STDIN_FILENO,buf,sizeof(buf));
	printf("buf=%s\n",buf);
	return 0;
}