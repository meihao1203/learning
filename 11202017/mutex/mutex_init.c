#include<stdio.h>
#include<pthread.h>
int main(void)
{
	pthread_mutex_t pmt;
	int ret = pthread_mutex_init(&pmt,NULL);
	if(0!=ret)
	{
		printf("pthread_mutex_init error\n");
		return -1;
	}
	printf("pthread_mutex_init success\n");
	ret = pthread_mutex_destroy(&pmt);
	if(0!=ret)
	{
		printf("pthread_mutex_destroy error\n");
		return -1;
	}
	return 0;
}