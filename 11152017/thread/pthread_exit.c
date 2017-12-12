#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void *thread_func(void *p)
{
	strcpy(p,"hello,world!");
	printf("I am a child thread %s\n",(char*)p);
	printf("child p is %x\n",p);
	pthread_exit((void*)0);
}
int main(void)
{
	pthread_t pt_id;
	void *p = malloc(20*sizeof(char));
	printf("p is %x\n",p);
	printf("I am a father thread %s\n",(char*)p);
	pthread_create(&pt_id,NULL,thread_func,p);
	sleep(2);
	printf("I am a father thread after sleep %s\n",(char*)p);
	return 0;
}