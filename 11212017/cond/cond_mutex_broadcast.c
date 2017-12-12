#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
typedef struct
{
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	int i;
}cm,*pcm;
void *pthFunc(void *p)
{
	pcm p1 = (pcm)p;
	int a = p1->i;
	pthread_mutex_lock(&p1->mutex);
	printf("thread %d will wait\n",a);
	pthread_cond_wait(&p1->cond,&p1->mutex);
	printf("thread %d  wake\n",a);
	pthread_mutex_unlock(&p1->mutex);
	pthread_exit((void*)a);
}
int main(void)
{
	cm p;
	pthread_mutex_init(&p.mutex,NULL);
	pthread_cond_init(&p.cond,NULL);
	pthread_t pth_id[5];
	for(int i=0;i<5;i++)
	{
		p.i = i+1;
		pthread_create(&pth_id[i],NULL,pthFunc,(void*)&p);
		sleep(1);
	}
	//sleep(1);
	pthread_cond_broadcast(&p.cond);
	sleep(1);
	printf("I am main thread , I wait child\n");
	int val;
	for(int i=0;i<5;i++)
	{
		pthread_join(pth_id[i],(void**)&val);
		printf("exit thread is %d \n",(int)val);
	}
	pthread_mutex_destroy(&p.mutex);
	pthread_cond_destroy(&p.cond);
	return 0;
}