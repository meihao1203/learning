#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t m1;
void *pthFunc(void *p)
{
	pthread_mutex_lock(&m1);
	printf("I get lock\n");
	pthread_exit(NULL);
}
int main(void)
{
	pthread_mutex_init(&m1,NULL);
	pthread_t pth;
	pthread_create(&pth,NULL,pthFunc,NULL);
	sleep(1);
	int ret = pthread_mutex_trylock(&m1);
	printf("error number is %d\n",ret);
	pthread_mutex_destroy(&m1);
	return 0;
}