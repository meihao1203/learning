#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	if( fork()>0 )
	{
		exit(0);
	}
	else
	{
		setsid();
		chdir("/");
		umask(0);
		for(int i=0;i<3;i++)
		{
			close(i);
		}
	}
	char buf[]="I have run 5s\n";
	int fd = open("/tmp/daemon.log",O_CREAT|O_WRONLY|O_APPEND,0666);
	if(-1==fd)
	{
		perror("open");
		exit(0);
	}
	while(1)
	{
		write(fd,buf,strlen(buf));
		sleep(5);
	}
}