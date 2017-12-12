#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct node
{
	int num;
	struct node *next;
}node,*pnode;
static pnode head = NULL;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void cleanFunc(void *args)
{
	printf("I am cleanFunc\n");
	pthread_mutex_unlock(&mutex);
}
void *pthFunc(void *args)
{
	pnode p = NULL;
	while(1)
	{
		pthread_cleanup_push(cleanFunc,NULL);
		pthread_mutex_lock(&mutex);
		if(NULL==head)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		printf("consume %d \n",head->num);
		p = head;
		head = head->next;
		free(p);
		if(NULL==head)
		{
			pthread_mutex_unlock(&mutex);
			pthread_exit((void*)1);
		}
		pthread_mutex_unlock(&mutex);
		sleep(1);
		pthread_cleanup_pop(0);
	}
}
int main(void)
{
	pthread_t pthId;
	pthread_create(&pthId,NULL,pthFunc,NULL);
	pnode p = NULL;
	for(int i=0;i<5;i++)
	{
		p = (pnode)calloc(1,sizeof(node));
		pthread_mutex_lock(&mutex);
		p->num = i+1;
		p->next = head;
		head = p;
		printf("product %d\n",p->num);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_join(pthId,NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}