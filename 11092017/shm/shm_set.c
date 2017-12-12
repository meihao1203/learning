#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
int main()
{
	int shmid = shmget( (key_t)1234,1024,IPC_CREAT|0600 );
	struct shmid_ds buf;
	int ret = shmctl(shmid,IPC_STAT,&buf);
	if( -1==ret )
	{
		perror("shmctl");
		exit(-1);
	}
	printf("cuid=%d , mode=%d , size=%ld , nattch=%ld\n",buf.shm_perm.cuid , buf.shm_perm.mode , buf.shm_segsz , buf.shm_nattch);
	buf.shm_perm.mode=0666;
	shmctl(shmid,IPC_SET,&buf);
	printf("cuid=%d , mode=%d , size=%ld , nattch=%ld\n",buf.shm_perm.cuid , buf.shm_perm.mode , buf.shm_segsz , buf.shm_nattch);
	return 0;
}