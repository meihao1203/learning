#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	int semid = semget( (key_t)1234 , 2 , IPC_CREAT|0600 );
	struct semid_ds buf;
	memset(&buf,0,sizeof(buf));
	int ret = semctl(semid,0,IPC_STAT,&buf);
	printf("uid=%d cuid=%d mode=%o nsems=%ld\n",buf.sem_perm.uid , buf.sem_perm.cuid , buf.sem_perm.mode , buf.sem_nsems);
	buf.sem_perm.mode = 0666;
	semctl(semid,0,IPC_SET,&buf);
	return 0;
}