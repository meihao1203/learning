#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<string.h>
int main()
{
	int shmid = shmget( (key_t)1234 , 20 , IPC_CREAT|0600 );
	int *i = (int *)shmat(shmid,NULL,0);
	int semid = semget( (key_t)1234 , 1 , IPC_CREAT|0600 );
	struct sembuf sp;
	memset(&sp,0,sizeof(sp));
	sp.sem_num = 0;
	sp.sem_op = -1;
	sp.sem_flg = SEM_UNDO;

	struct sembuf sv;
	memset(&sv,0,sizeof(sv));
	sv.sem_num = 0;
	sv.sem_op = 1;
	sv.sem_flg = SEM_UNDO;

	for(int j=0;j<1e7;j++)
	{
		semop(semid,&sp,1);
		(*i)++;
		semop(semid,&sv,1);
	}
	return 0;
}