#include<stdio.h>
#include<pthread.h>
int t = 0;
pthread_mutex_t pmt;
void *pthFunc(void *p)
{
	for(int i=0;i<2e7;i++)
	{
		pthread_mutex_lock(&pmt);
		t++;
		pthread_mutex_unlock(&pmt);
	}
	pthread_exit(NULL);
}
int main(void)
{	
	pthread_t pth_id;
	int ret = pthread_create(&pth_id,NULL,pthFunc,NULL);
	if(0!=ret)
	{
		printf("pthread_create error\n");
		return -1;
	}
	pthread_mutex_init(&pmt,NULL);
	for(int i=0;i<2e7;i++)
	{
		pthread_mutex_lock(&pmt);
		t++;
		pthread_mutex_unlock(&pmt);
	}
	pthread_join(pth_id,NULL);
	printf("final t = %d\n",t);
	pthread_mutex_destroy(&pmt);
	return 0;
}