#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
static pthread_mutex_t mutex;
static pthread_cond_t cond;
static int ticketcount = 5;
void *pthFunc1(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(ticketcount>0)
		{
			printf("thread 1 sell ticket , ticket number is %d\n",ticketcount);
			ticketcount--;
			if(0==ticketcount)
			{
				pthread_cond_signal(&cond);
			}
			printf("after sell , remain ticket is %d\n",ticketcount);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
void *pthFunc2(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(ticketcount>0)
		{
			printf("thread 2 sell ticket , ticket number is %d\n",ticketcount);
			ticketcount--;
			if(0==ticketcount)
			{
				pthread_cond_signal(&cond);
			}
			printf("after sell , remain ticket is %d\n",ticketcount);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
void *pthFunc3(void *args)
{
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&cond,&mutex);
	ticketcount = 5;
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t pthId[3];
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&pthId[0],NULL,pthFunc1,NULL);
	pthread_create(&pthId[1],NULL,pthFunc2,NULL);
	pthread_create(&pthId[2],NULL,pthFunc3,NULL);
	pthread_join(pthId[0],NULL);
	pthread_join(pthId[1],NULL);
	pthread_join(pthId[2],NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;

}
