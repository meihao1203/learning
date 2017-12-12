#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{	
	int semid = semget( (key_t)1234 , 2 , IPC_CREAT|0600 );
	unsigned short arr[2]={1,2};
	printf("arr[0]=%d arr[1]=%d\n",arr[0],arr[1]);
	int ret = semctl(semid,0,SETALL,arr);
	printf("ret=%d\n",ret);
	memset(arr,0,sizeof(arr));
	printf("arr[0]=%d arr[1]=%d\n",arr[0],arr[1]);
	semctl(semid,0,GETALL,arr);
	printf("arr[0]=%d arr[1]=%d\n",arr[0],arr[1]);
	ret = semctl(semid,0,IPC_RMID);
	if(-1==ret)
	{
		perror("semctl");
		exit(-1);
	}
	printf("ret=%d\n",ret);
	return 0;
}