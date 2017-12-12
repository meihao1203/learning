#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
int main()
{
	int semid = semget( (key_t)1234 , 2 , IPC_CREAT|0600 );
	//unsigned short array[2] = {0,10};
	//semctl(semid,0,SETALL,array);
	struct sembuf s[2];
	memset(&s,0,sizeof(s));
	s[0].sem_num = 0;
	s[0].sem_op = -1;
	s[0].sem_flg = SEM_UNDO;

	s[1].sem_num = 1;
	s[1].sem_op = 1;
	s[1].sem_flg = SEM_UNDO;

	while(1)
	{
		printf("product num is %d , consumer num is %d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
		printf("-------------------------\n");
		semop(semid,&s[0],1);
		printf("I will consume\n");
		semop(semid,&s[1],1);
		printf("*************************\n");
		printf("product num is %d , consumer num is %d\n\n\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
		sleep(3);
	}
	return 0;
}