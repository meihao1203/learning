#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void *pth_func(void *p)
{
	printf("I am child\n");
	char buf[128];
	read(STDIN_FILENO,buf,sizeof(buf));
	printf("after read\n");
	pthread_exit((void*)5);
}
int main(void)
{
	pthread_t pth_id;
	int ret = pthread_create(&pth_id , NULL , pth_func , NULL);
	if( 0!=ret )
	{
		printf("pthread_create error\n");
		return -1;
	}
	sleep(2);
	ret = pthread_cancel(pth_id);
	if( 0!=ret )
	{
		printf("pthread_cancel failed ret =%d\n",ret);
		return -1;
	}
	int i;
	pthread_join(pth_id,(void**)&i);
	printf("main thread i = %d\n",(int)i);
	return 0;
}