#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
int main(void)
{
	int semid = semget(IPC_PRIVATE,1,IPC_CREAT|0600);
	//semctl(semid,0,SETVAL,1);
	if(fork())
	{
	semctl(semid,0,SETVAL,1);
		printf("I am father. sem'val =%d\n",semctl(semid,0,GETVAL));
		while(1);
	}
	else
	{
	semctl(semid,0,SETVAL,1);
		printf("I am father. sem'val =%d\n",semctl(semid,0,GETVAL));
		while(1);
	}
	return 0;
}
