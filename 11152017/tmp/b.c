#include"func.h"

pchat sp;
void handle(int sig)
{
        close(sp->fd1);
        close(sp->fd2);
        ((pdata)(sp->pshm))->flag=2;
        shmdt(sp->pshm);
        shmctl(sp->shmid,IPC_RMID,NULL);
        semctl(sp->semid,0,IPC_RMID);
        exit(0);
}

int main()
{
        chat a;
        memset(&a,0,sizeof(a));
        sp=&a;
        int ret;
        a.shmid=shmget((key_t)1001,4096,IPC_CREAT|0600);
        if(a.shmid==-1)
        {
                perror("shmget");
                return -1;
        }
        a.pshm=shmat(a.shmid,NULL,0);
        if((void*)-1==a.pshm)
        {
                perror("shmat");
                return -1;
        }
        a.semid=semget((key_t)1001,1,IPC_CREAT|0600);
        if(a.semid==-1)
        {
                perror("semget");
                return -1;
        }
        ret=semctl(a.semid,0,SETVAL,1);
        if(ret!=0)
        {
                perror("semctl");
                return -1;
        }
        signal(SIGINT,handle);
        a.fd1=open("1.pipe",O_WRONLY);
        if(a.fd1==-1)
        {
                perror("open");
                return -1;
        }
        a.fd2=open("2.pipe",O_RDONLY);
        if(a.fd2==-1)
        {
                perror("open");
                return -1;
        }
        printf("open pipe success\n");
        pid_t pid;
        pid=getpid();
        write(a.fd1,&pid,sizeof(pid));
        fd_set rdset;
        struct sembuf semp,semv;
        semp.sem_num=0;
        semp.sem_op=-1;
        semp.sem_flg=SEM_UNDO;
        semv.sem_num=0;
        semv.sem_op=1;
        semv.sem_flg=SEM_UNDO;
        pdata data1=(pdata)(a.pshm);
        while(1)
        {
                FD_ZERO(&rdset);
                FD_SET(0,&rdset);
                FD_SET(a.fd2,&rdset);
                ret=select(a.fd2+1,&rdset,NULL,NULL,NULL);
                if(ret>0)
                {
                        if(FD_ISSET(0,&rdset))
                        {
                                semop(a.semid,&semp,1);       
                                memset(data1,0,sizeof(data));
                                read(0,data1->buf,sizeof(data1->buf));
                                data1->flag=3;
                                semop(a.semid,&semv,1);
                                write(a.fd1,data1->buf,strlen(data1->buf)-1);

                        }
                        if(FD_ISSET(a.fd2,&rdset))
                        {
                                semop(a.semid,&semp,1);
                                memset(data1,0,sizeof(data));
                                read(a.fd2,data1->buf,sizeof(data1->buf));
                                data1->flag=1;
                                semop(a.semid,&semv,1);
                        }
                }
        }
        return 0;
}