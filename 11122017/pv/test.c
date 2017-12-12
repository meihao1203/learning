#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
union semun //这个必须定义
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}arg;
int main()
{
           int semid=semget((key_t)1234,2,IPC_CREAT|0600);
           if(-1==semid)
           {
                   perror("semget");
                   return -1;
           }
		   unsigned short array[2]={1,2};
		  // union semun arg;
		   arg.array = array;
           semctl(semid,0,SETALL,arg);
		  //semctl(semid,0,SETVAL,*(arg.array));
		  //semctl(semid,1,SETVAL,*(arg.array+1));
		  //semctl(semid,0,SETALL,array);
          memset(array,0,sizeof(array));   
          printf("after memset array[0]=%d,array[1]=%d\n",array[0],array[1]);
          int ret=semctl(semid,0,GETALL,array);
          if(-1==ret)
          {
                   perror("semctl");
                   return -1;
          }
          printf("after get array[0]=%d,array[1]=%d\n",array[0],array[1]);
		  printf("sem1's value = %d\n",semctl(semid,0,GETVAL));
		  printf("sem2's value = %d\n",semctl(semid,1,GETVAL));
          ret = semctl(semid,0,IPC_RMID);    
          return 0;
}