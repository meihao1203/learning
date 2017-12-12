#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
void change_nonblock(int fd)
{
	int status = fcntl(fd,F_GETFL);
	status = status|O_NONBLOCK;
	int ret = fcntl(fd,F_SETFL,status);
	if(-1==ret)
	{
		perror("fcntl");
		return;
	}
}
int main(void)
{	
	char buf[5];
	sleep(2);
	change_nonblock(0);
	int ret = read(0,buf,sizeof(buf));
	printf("ret =%d\n",ret);
	printf("errno =%d\n",errno);
	printf("buf =%s\n",buf);
	return 0;
}