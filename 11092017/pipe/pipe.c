#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int fds[2];
	pipe(fds);
	if( !fork() )
	{
		close(fds[1]);
		char buf[128];
		read(fds[0],buf,sizeof(buf));
		printf("buf=%s\n",buf);
		close(fds[0]);
		exit(0);
	}
	else
	{
		close(fds[0]);
		write(fds[1],"hello",5);
		wait(NULL);
		close(fds[1]);
		exit(0);
	}
	return 0;
}