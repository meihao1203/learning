#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int semid = semget( (key_t)1234 , 1 , IPC_CREAT|0600 );
	if(-1==semid)
	{
		perror("semget");
		exit(-1);
	}
	int ret = semctl(semid,0,SETVAL,5);
	if(-1==ret)
	{
		perror("semctl");
		exit(-1);
	}
	printf("ret=%d\n",ret);
	ret = semctl(semid,0,GETVAL,NULL);
	printf("ret=%d\n",ret);
	return 0;
}