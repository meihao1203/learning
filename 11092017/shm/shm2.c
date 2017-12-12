#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#define SIZE 20
int main(int argc,char **argv)
{
	if( 2!=argc )
	{
		write(0,"error args\n",11);
		return -1;
	}
	key_t key;
	key = ftok(argv[1],1);
	int id;
	id = shmget(key,SIZE,IPC_CREAT|0600);
	if( -1==id )
	{
		perror("shmget");
		return -1;
	}
	char *p =(char *)shmat(id,NULL,0);
	printf("%c\n",p[0]);
	sleep(10);
	shmdt(p);
	return 0;
}