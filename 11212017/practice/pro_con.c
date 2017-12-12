#include<stdio.h>
#include<pthread.h>
typedef struct node
{
	int num;
	struct node *next;
}node,*pnode;
static pnode head = NULL;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void *pthFunc(void *args)
{
	
}
int main(void)
{
	pthread_t pthId;
	pthread_create(&pthId,NULL,pthFunc,NULL);
	pnode p = NULL;
	for(int i=0;i<10;i++)
	{
		p = (pnode)calloc(1,sizeof(node));
		pthread_mutex_lock(&mutex);
		p->next = head;
		head = p;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_cancel(pthId);
	pthread_join(pthId,NULL);
	pthread_mutex_destroy(&mutex);

}