#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
typedef struct student
{
	int num ;
	char name[20];
}stu,*pstu;
int main()
{
	int shmid = shmget((key_t)110,sizeof(stu),IPC_CREAT|0666);
	pstu p = (pstu)shmat(shmid,NULL,0);
	p->num = 2017;
	strcpy(p->name,"meihao");
	//shmdt(p);
	while(1);
	return 0;
}
