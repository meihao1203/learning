#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int shmid = shmget(IPC_PRIVATE,1024,IPC_CREAT|0666);
	if( fork() )
	{
		char *p = (char*)shmat(shmid,NULL,0);
		char buf[128];
		strcpy(p,"hello , world!");
		sleep(10);
		shmdt(p);
		wait(NULL);
		int ret = shmctl(shmid,IPC_RMID,0);
		if(0!=ret)
		{
			perror("shmctl");
			exit(0);
		}
	}
	else 
	{
		char *p = (char*)shmat(shmid,NULL,0);
		char buf[128];
		strcpy(buf,p);
		printf("buf=%s\n",p);
		sleep(10);
		shmdt(p);
		exit(0);
	}
	return 0;
}