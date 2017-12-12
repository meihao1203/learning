#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void *thread_func(void *p)
{
	strcpy(p,"hello,world!");
	printf("I am child thread  , p's address = %x\n",p);
	printf("child thread p=%s\n",(char*)p);
	return 0;
}
int main(void)
{
	pthread_t pt_id;
	void *p = malloc(20*sizeof(char));
	pthread_create(&pt_id,NULL,thread_func,p);
	printf("p's address = %x\n",p);
	sleep(2);
	printf("main thread , p=%s\n",(char*)p);
	return 0;
}