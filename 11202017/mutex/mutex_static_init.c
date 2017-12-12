#include<stdio.h>
#include<pthread.h>
int main(void)
{
	pthread_mutex_t pmt = PTHREAD_MUTEX_INITIALIZER;
	printf("pthread_mutex_init success\n");
	int ret = pthread_mutex_destroy(&pmt);
	if(0!=ret)
	{
		printf("pthread_mutex_destroy error\n");
		return -1;
	}
	return 0;
}
