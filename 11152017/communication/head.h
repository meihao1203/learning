#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
typedef struct 
{
	int fd1;
	int fd2;
	char pipe1[20];
	char pipe2[20];
	int shmid;
	int semid;
	void *pshm;
	pid_t pid;
}chat,*pchat;
typedef struct
{
	int flag;
	char buf[1024];
}data,*pdata;