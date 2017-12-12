#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<time.h>
#include<strings.h>
#include<string.h>

void sigFunc(int sig)
{
	time_t t;
	bzero(&t,sizeof(t));
	time(&t);
	struct tm *p;
	p = gmtime(&t);
	printf("%2d:%2d:%2d\n",p->tm_hour , p->tm_min , p->tm_sec);
}
int main(void)
{
	signal(SIGALRM,sigFunc);
	kill(0,SIGALRM);
	struct itimerval rt;
	bzero(&rt,sizeof(rt));
	rt.it_value.tv_sec = 5;
	rt.it_interval.tv_sec = 2;
	setitimer(ITIMER_REAL,&rt,NULL);
	while(1);
	return 0;
}