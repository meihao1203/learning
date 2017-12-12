#include"head.h"
#define maxshmsize 2048
int main(void)
{
	chat b1;
	memset(&b1,0,sizeof(b1));
	b1.shmid = shmget( (key_t)1001,maxshmsize,IPC_CREAT|0666 );
	b1.semid = semget( (key_t)1001,1,IPC_CREAT|0666 );
	b1.pshm = shmat(b1.shmid,NULL,0);
	struct sembuf sp,sv;
	bzero(&sp,sizeof(sp));
	bzero(&sv,sizeof(sv));
	sp.sem_num = 0;
	sp.sem_op = -1;
	sp.sem_flg = SEM_UNDO;

	sv.sem_num = 0;
	sv.sem_op = 1;
	sv.sem_flg = SEM_UNDO;

	pdata pbd1 = (pdata)b1.pshm;
	
	while(1)
	{
		semop(b1.semid,&sp,1);
		if(pbd1->flag==1)
		{
			printf("A:%s\n",pbd1->buf);
			pbd1->flag = 0;
		}
		else if(pbd1->flag==3)
		{
			(pbd1->buf)[strlen(pbd1->buf)-1] = '\0';
			printf("%*s%s\n",50,pbd1->buf," :b");
			pbd1->flag = 0;
		}
		else if(pbd1->flag==2)
		{
			semop(b1.semid,&sv,1);
			printf("--------bye--------\n");
			exit(0);
		}
		semop(b1.semid,&sv,1);
	}
	return 0;
}