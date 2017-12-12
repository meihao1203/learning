#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
typedef struct
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}mc,*pmc;
void *pthFunc(void *p)
{
	pmc p1 = (pmc)p;
	pthread_mutex_lock(&p1->mutex);
	printf("I am wait\n");
	pthread_cond_wait(&p1->cond,&p1->mutex);
	printf("condition success\n");
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
	printf("I am main thread\n");
	pthread_cond_destroy(&p1.cond);
	pthread_mutex_destroy(&p1.mutex);
	return 0;
}