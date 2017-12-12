#include<stdio.h>
#include<pthread.h>
void *thread_func(void *p)
{
	printf("I am child thread\n");
	while(1);
}
int main(void)
{
	pthread_t th_id;
	int ret = pthread_create(&th_id,NULL,thread_func,NULL);
	if(0!=ret)
	{
		printf("thread create failed!\n");
		return -1;
	}
	while(1);
	return 0;
}