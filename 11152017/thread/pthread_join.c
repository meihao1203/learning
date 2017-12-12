#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void *thread_func(void *p)
{
	strcpy((char*)p,"hello,world!");
	printf("I am child thread\n");
	printf("child p is %p\n",p);
	pthread_exit((void*)5);
}
int main(void)
{
	pthread_t pt_id;
	void *p = malloc(20*sizeof(char));
	printf("p is %x\n",p);
	pthread_create(&pt_id,NULL,thread_func,p);
	//int i;
	void *i;
	//pthread_join(pt_id,(void**)&i);
	pthread_join(pt_id,(void**)&i);
	printf("main thread %s\n",(char*)p);
	//printf("main thread i=%d\n",i);
	//printf("main thread i=%d\n",(int)((int*)i));
	printf("main thread i=%d\n",(int)i);
	return 0;
}