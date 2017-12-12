#include"head.h"
#define maxshmsize 2048
int main(void)
{
	chat a1;
	memset(&a1,0,sizeof(a1));
	a1.shmid = shmget( (key_t)1000,maxshmsize,IPC_CREAT|0666 );
	a1.semid = semget( (key_t)1000,1,IPC_CREAT|0666 );
	a1.pshm  = shmat(a1.shmid,NULL,0);
	struct sembuf sp,sv;
	bzero(&sp,sizeof(sp));
	bzero(&sv,sizeof(sv));
	sp.sem_num = 0;
	sp.sem_op = -1;
	sp.sem_flg = SEM_UNDO;

	sv.sem_num = 0;
	sv.sem_op = 1;
	sv.sem_flg = SEM_UNDO;
	
	pdata pad1 = (pdata)a1.pshm;

	while(1)
	{
		semop(a1.semid,&sp,1);
		if(pad1->flag==1)
		{
			printf("B:%s\n",pad1->buf);
			pad1->flag = 0;
		}
		else if(pad1->flag==3)
		{
			printf("%*sA:%s",30," ",pad1->buf);
			pad1->flag = 0;
		}
		semop(a1.semid,&sv,1);
	}
	return 0;

}