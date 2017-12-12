#include<signal.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<sys/select.h>
typedef struct
{
        int fd1;
        int fd2;
        char pipe1[10];
        char pipe2[10];
        pid_t pid;
        void* pshm;
        int shmid;
        int semid;
}chat,*pchat;

typedef struct
{
        int flag;
        char buf[512];
}data,*pdata;