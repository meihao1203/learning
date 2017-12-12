#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
typedef struct
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}mc,*pmc;
void *pthFunc(void *p)
{
	pmc p1 = (pmc)p;
	pthread_mutex_lock(&p1->mutex);
	printf("I will wait\n");
	struct timespec abstime;
	memset(&abstime,0,sizeof(abstime));
	abstime.tv_sec = time(NULL)+5;
	int ret = pthread_cond_timedwait(&p1->cond,&p1->mutex,&abstime);
	printf("ret = %d\n",ret);
	pthread_mutex_unlock(&p1->mutex);
	pthread_exit(NULL);
}
int main()
{
	mc p1;
	pthread_t th_id;
	pthread_mutex_init(&p1.mutex,NULL);
	pthread_cond_init(&p1.cond,NULL);
	pthread_create(&th_id,NULL,pthFunc,(void*)&p1);
	sleep(2);
	pthread_cond_signal(&p1.cond);
	pthread_join(th_id,NULL);
	printf("I am main thread , I wait child\n");
	pthread_cond_destroy(&p1.cond);
	pthread_mutex_destroy(&p1.mutex);
	return 0;
}