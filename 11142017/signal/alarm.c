#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void sigFunc(int sig)
{
	printf("I am sig %d\n",sig);
}
int main(void)
{
	signal(SIGALRM,sigFunc);
	sleep(3);
	printf("sleep over\n");
	alarm(1);
	printf("alarm over\n");
	while(1);
	return 0;
}