#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void clean(void *p)
{
	printf("I am clean , p =%s\n",(char*)p);
	free(p);
}
void *pthFunc(void *p)
{
	p = malloc(20);
	pthread_cleanup_push(clean,p);
	printf("I am child\n");
	strcpy(p,"hello");
	char buf[128];
	read(0,buf,sizeof(buf));
	printf("after read\n");
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
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
	//sleep(1);
	//pthread_cancel(pth_id);
	void *q;
	pthread_join(pth_id,(void**)&q);
	printf("main thread q =%d\n",(int)q);
	return 0;
}