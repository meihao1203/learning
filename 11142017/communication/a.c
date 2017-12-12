#include"head.h"
#define maxshmsize 2048
int main(void)
{
	chat a;
	memset(&a,0,sizeof(a));
	mkfifo("1.pipe",0666);
	strcpy(a.pipe1,"1.pipe");
	mkfifo("1.pipe",0666);
	strcpy(a.pipe2,"2.pipe");
	a.shmid = shmget( (key_t)1000,maxshmsize,IPC_CREAT|0666);
	a.semid = semget( (key_t)1000,1,IPC_CREAT|0666 );
	a.pshm = shmat(a.shmid,NULL,0);
	a.fd1 = open("1.pipe",O_RDONLY);
	a.fd2 = open("2.pipe",O_WRONLY);

	struct sembuf sp,sv;
	bzero(&sp,sizeof(sp));
	bzero(&sv,sizeof(sv));
	sp.sem_num = 0;
	sp.sem_op = -1;
	sp.sem_flg = SEM_UNDO;

	sv.sem_num = 0;
	sv.sem_op = 1;
	sv.sem_flg = SEM_UNDO;

	read(a.fd1,&a.pid,sizeof(a.pid));
	printf("b's pid =%d\n",a.pid);

	data ad;
	bzero(&ad,sizeof(ad));
	pdata pad;
	pad = (pdata)a.pshm;

	fd_set readset;
	int ret;
	while(1)
	{
		FD_ZERO(&readset);
		FD_SET(0,&readset);
		FD_SET(a.fd1,&readset);
		ret = select(a.fd1+1,&readset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(0,&readset))
			{
				semop(a.semid,&sp,1);
				bzero(pad,sizeof(data));
				read(0,pad->buf,sizeof(pad->buf));
				pad->flag = 3;
				semop(a.semid,&sv,1);
				write(a.fd2,pad->buf,strlen(pad->buf)-1);
			}
			if(FD_ISSET(a.fd1,&readset))
			{
				semop(a.semid,&sp,1);
				bzero(pad,sizeof(data));
				read(a.fd1,pad->buf,sizeof(pad->buf));
				pad->flag = 1;
				semop(a.semid,&sv,1);
			}
		}
	}
	return 0;
}
