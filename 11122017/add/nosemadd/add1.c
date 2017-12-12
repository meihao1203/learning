#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
int main()
{
	int shmid = shmget( (key_t)1234 , 20 , IPC_CREAT|0600 );
	int *i = (int *)shmat(shmid,NULL,0);
	for(int j=0;j<1e7;j++)
	{
		(*i)++;
	}
	return 0;
}