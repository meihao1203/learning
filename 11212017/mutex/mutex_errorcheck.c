#include<stdio.h>
#include<pthread.h>
int main(void)
{
	pthread_mutex_t m1;
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_ERRORCHECK_NP);
	pthread_mutex_init(&m1,&mutexattr);
	pthread_mutex_lock(&m1);
	printf("I lock success\n");
	int ret = pthread_mutex_lock(&m1);
	printf("ret = %d\n",ret);
	printf("I lock twice\n");
	return 0;
}