#include"head.h"
#define maxshmsize 2048
static pchat sp;
void sigFunc(int sig)
{
	((pdata)sp->pshm)->flag = 2;
	shmdt(sp->pshm);
	shmctl(sp->shmid,IPC_RMID,NULL);
	semctl(sp->semid,0,IPC_RMID);
	exit(0);
}
int main(void)
{
	signal(SIGINT,sigFunc);
	chat b;
	sp = &b;
	memset(&b,0,sizeof(b));
	strcpy(b.pipe1,"1.pipe");
	strcpy(b.pipe2,"2.pipe");
	b.shmid = shmget( (key_t)1001,maxshmsize,IPC_CREAT|0666 );
	b.semid = semget( (key_t)1001,1,IPC_CREAT|0666 );
	b.pshm = shmat(b.shmid,NULL,0);
	b.fd1 = open("1.pipe",O_WRONLY);
	b.fd2 = open("2.pipe",O_RDONLY);

	b.pid = getpid();
	write(b.fd1,&b.pid,sizeof(b.pid));
	printf("send pid success!\n");

	semctl(b.semid,0,SETVAL,1);
	struct sembuf sp,sv;
	bzero(&sp,sizeof(sp));
	bzero(&sv,sizeof(sv));
	sp.sem_num = 0;
	sp.sem_op = -1;
	sp.sem_flg = SEM_UNDO;

	sv.sem_num = 0;
	sv.sem_op = 1;
	sv.sem_flg = SEM_UNDO;

	pdata pbd;
	pbd = (pdata)b.pshm;
	
	fd_set readset;
	int ret;
	while(1)
	{
		FD_ZERO(&readset);
		FD_SET(0,&readset);
		FD_SET(b.fd2,&readset);
		ret = select(b.fd2+1,&readset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(0,&readset))
			{
				semop(b.semid,&sp,1);
				bzero(pbd,sizeof(data));
				read(0,pbd->buf,sizeof(pbd->buf));
				pbd->flag = 3;
				semop(b.semid,&sv,1);
				write(b.fd1,pbd->buf,strlen(pbd->buf)-1);
			}
			if(FD_ISSET(b.fd2,&readset))
			{
				semop(b.semid,&sp,1);
				bzero(pbd,sizeof(data));
				read(b.fd2,pbd->buf,sizeof(pbd->buf));
				pbd->flag = 1;
				semop(b.semid,&sv,1);
			}
		}
	}
	return 0;
}