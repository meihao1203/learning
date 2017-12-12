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
	int num;
	char name[20];
}stu,*pstu;
int main()
{
	int shmid = shmget( (key_t)110,sizeof(stu),IPC_CREAT|0666 );
	stu s;
	pstu p = shmat(shmid,NULL,0);
	memcpy(&s,p,sizeof(stu));
	printf("read struct num=%d  name=%s\n",s.num,s.name);
	shmdt((void *)p);
	int ret = shmctl(shmid,IPC_RMID,NULL);
	if(0!=ret)
	{
		perror("shmctl");
		exit(0);
	}

	return 0;
}
