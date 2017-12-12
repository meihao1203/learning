#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
int main(int argc,char **argv)
{
	int fd1 = open(argv[1],O_RDWR);
	char buf[32];
	read(fd1,buf,10);
	printf("fd1=%d  buf=%s\n",fd1,buf);
	int fd2 = fd1;
	int fd3 = dup(fd1);
	printf("fd2=%d\n",fd2);
	printf("fd3=%d\n",fd3);
	close(fd1);
	printf("---------------------------\n");
	bzero(buf,sizeof(buf));
	read(fd2,buf,10);
	printf("fd2=%d  buf=%s\n",fd2,buf);
	close(fd2);
	bzero(buf,sizeof(buf));
	read(0,buf,10);
	printf("fd3=%d  buf=%s\n",fd3,buf);
	close(fd3);
	return 0;
}
