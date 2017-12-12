#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
void *pth_func(void *p)
{
	p = malloc(20*sizeof(char));
	strcpy(p,"hello");
	printf("I am child thread\n");
	printf("child p is %p\n",p);
	return p;
}
int main(void)
{
	pthread_t pt_id;
	pthread_create(&pt_id,NULL,pth_func,NULL);
	char *p;
	int ret = pthread_join(pt_id,(void**)&p);
	if(0!=ret)
	{
		printf("pthread_join error\n");
		return -1;
	}
	printf("p = %p\n",p);
	printf("p = %s\n",p);
	return 0;
}