#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char **argv)
{	
	if( 2!=argc )
	{
		write(0,"error args\n",11);
		return -1;
	}
	int fd = open(argv[1],O_RDWR);
	if( fork()>0 )
	{
		close(fd);
		//wait(NULL);
		return 0;
	}
	else
	{
		sleep(5);   //等待父进程关闭打开的文件描述符
		char buf[]="hello , world!";
		write(fd,buf,strlen(buf));
		close(fd);
		//exit(0);
		return 0;
	}
	return 0;
}