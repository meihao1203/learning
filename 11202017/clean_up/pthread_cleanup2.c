#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void clean1(void *p)
{
	printf("I am clean func %d\n",(int)p);
}
void clean2(void *p)
{
	printf("I am clean fun2 %d\n",(int)p);
}
void *pthFunc(void *p)
{
	pthread_cleanup_push(clean1,(void*)1);
	pthread_cleanup_push(clean2,(void*)2);
	printf("I am child\n");
	char buf[128];
	read(0,buf,sizeof(buf));
	printf("after read\n");
	pthread_exit((void*)5);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
}
int main(void)
{
	pthread_t pt_id;
	int ret = pthread_create(&pt_id,NULL,pthFunc,(void*)1);
	if(0!=ret)
	{
		printf("pthread_create error\n");
		return -1;
	}
	pthread_cancel(pt_id);
	void *p;
	pthread_join(pt_id,&p);
	//pthread_join(pt_id,NULL);
	printf("man thread p =%d\n",(int)p);
	return 0;
}