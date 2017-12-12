#include<stdio.h>
#include<pthread.h>
void *thread_func(void *p)
{
	int	i = (int)p;
	printf("I am child thread , arg = %d\n",i);
	while(1);
}
int main(void)
{
	pthread_t th_id;
	int ret = pthread_create(&th_id,NULL,thread_func,(void*)1);
	if(0!=ret)
	{
		printf("thread create failed!\n");
		return -1;
	}
	while(1);
	return 0;
}