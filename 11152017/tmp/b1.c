#include"func.h"

int main()
{
        int shmid=shmget((key_t)1001,4096,0600);
        if(shmid==-1)
        {
                perror("shmget");
                return -1;
        }
        pdata pd1=(pdata)shmat(shmid,NULL,0);
        if(pd1==(pdata)-1)
        {
                perror("shmat");
                return -1;
        }
        int semid=semget((key_t)1001,1,0600);
        if(semid==-1)
        {
                perror("semget");
                return -1;
        }
        struct sembuf semp,semv;
        semp.sem_num=0;
        semp.sem_op=-1;
        semp.sem_flg=SEM_UNDO;       
        semv.sem_num=0;
        semv.sem_op=1;
        semv.sem_flg=SEM_UNDO;       
        while(1)
        {
                semop(semid,&semp,1);
                if(pd1->flag==1)
                {
                        printf("A:%s\n",pd1->buf);
                        pd1->flag=0;
                }
                else if(pd1->flag== 2)
                {
                        semop(semid,&semv,1);
                        printf("-----------------bye------------------\n");
                        exit(0);
                }
                else if(pd1->flag==3)
                {
                        (pd1->buf)[strlen(pd1->buf)-1] = '\0';
                        printf("%*s%s\n",50,pd1->buf," :B");
                        pd1->flag=0;
                }
                semop(semid,&semv,1);
        }       
        return 0;
}