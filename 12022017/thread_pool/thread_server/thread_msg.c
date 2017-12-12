#include"thread_msg.h"
void factory_init(pfactory f,int num,int capacity,thread_handle thread_func)
{
	f->thread = (pthread_t *)calloc(num,sizeof(pthread_t));
	f->num = num;
	f->capacity = capacity;
	que_init(&f->que_t);
	f->func = thread_func;
	pthread_cond_init(&f->cond,NULL);
	f->flag = 0;
}

void que_init(pque que_t)
{
	que_t->head = NULL;
	que_t->tail = NULL;
	pthread_mutex_init(&que_t->mutex,NULL);
	que_t->size = 0;
}

void *thread_func(void *p)
{
	pfactory f = (pfactory)p;
	int new_fd;
	while(1)
	{
		pthread_mutex_lock(&f->que_t.mutex);
		if(f->que_t.size==0)
		{
			pthread_cond_wait(&f->cond,&f->que_t.mutex);
		}
		que_get(f,&new_fd);
		pthread_mutex_unlock(&f->que_t.mutex);
 		sendfile(new_fd);	
	}
}

void factory_start(pfactory f)
{
	int i ;
	if(f->flag==0)
	{
		for(i=0;i<f->num;i++)
		{
			pthread_create(&f->thread[i],NULL,thread_func,(void*)f);
		}
	}
	f->flag=1;
}

void que_insert(pque que_t,int new_fd)
{
	pthread_mutex_lock(&que_t->mutex);
	pnode pnew = (pnode)calloc(1,sizeof(node));
	pnew->new_fd = new_fd;
	if(que_t->head==NULL)
	{
		que_t->head = pnew;
		que_t->tail = pnew;
	}
	que_t->tail->next = pnew;
	que_t->tail = pnew;
	(que_t->size)++;
	pthread_mutex_unlock(&que_t->mutex);
}

void que_get(pfactory f,int *new_fd)
{
	pnode pcur = f->que_t.head;
	*new_fd = pcur->new_fd;
	f->que_t.head = f->que_t.head->next;
	if(f->que_t.head==NULL)
	{	
		f->que_t.tail = NULL;
	}
	(f->que_t.size)--;
	free(pcur);
	pcur = NULL;
}