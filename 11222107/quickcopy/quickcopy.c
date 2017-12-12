#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<string.h>
#include<strings.h>
#define MAXFILENAMESIZE 128
#define MAXTHERAD 10
static int file_size;
static int new_file_size;
static char *file_point;
static char *new_file_point;
static int threadNum = 0;
void *pthFunc(void *args)
{
	int i = threadNum++;
	int srcpoint = (file_size/10)*i;
	int destpoint = srcpoint;
	if(i!=9)
	{
		memcpy(new_file_point+destpoint,file_point+srcpoint,file_size/10);
	}
	else
	{
		memcpy(new_file_point+destpoint,file_point+srcpoint,file_size-srcpoint);
	}
	pthread_exit(NULL);
}
int main(int argc,char **argv)
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	int fdr = open(argv[1],O_RDONLY,0666);
	if(-1==fdr)
	{
		printf("fdr open error\n");
		return -1;
	}
	char new_file_name[MAXFILENAMESIZE];
	sprintf(new_file_name,"%s%s","new_",argv[1]);
	int fdw = open(new_file_name,O_CREAT|O_RDWR,0666);
	if(-1==fdw)
	{
		printf("fdw open error\n");
		return -1;
	}
	struct stat buf1,buf2;
	bzero(&buf1,sizeof(buf1));
	bzero(&buf2,sizeof(buf2));
	fstat(fdr,&buf1);
	file_size = buf1.st_size;
	ftruncate(fdw,file_size);
	fstat(fdw,&buf2);
	new_file_size = buf2.st_size;
	file_point = (char*)mmap(NULL,file_size,PROT_READ,MAP_SHARED,fdr,0);  //prot只是读权限，则文件描述符要有可读权限
	new_file_point = (char*)mmap(NULL,new_file_size,PROT_WRITE,MAP_SHARED,fdw,0);   //prot是写权限，则文件描述符要有可读可写权限
	pthread_t pth[MAXTHERAD];
	for(int i = 0;i<10;i++)
	{
		pthread_create(&pth[i],NULL,pthFunc,NULL);
	}
	printf("start copying\n");
	for(int i = 0;i<10;i++)
	{
		pthread_join(pth[i],NULL);
	}
	printf("Done!\n");
	return 0;
}