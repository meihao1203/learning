#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main(void)
{
	int shmid = shmget( (key_t)1234 , 20 , IPC_CREAT|0600 );
	int *i = (int *)shmat(shmid,NULL,0);
	printf("i=%d\n",*i);
	//shmctl(shmid,IPC_RMID,NULL);
	return 0;
}