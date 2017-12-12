#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int shmid = shmget( (key_t)1234 , 20 , IPC_CREAT|0600 );
	int *i = shmat(shmid,NULL,0);
	*i=0;
	return 0;
}