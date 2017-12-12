#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
#include<sys/select.h>
#include<sys/time.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char **argv)
{
	if(3!=argc)
	{
		printf("error argcs\n");
		return -1;
	}
	int fdw = open(argv[1],O_WRONLY);
	int fdr = open(argv[2],O_RDONLY);
	printf("fdw=%d fdr=%d\n",fdw,fdr);
	char buf[128];
	fd_set rdset;
	int ret;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret = select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if( FD_ISSET(0,&rdset) )
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				write(fdw,buf,strlen(buf)-1);
			}
			if( FD_ISSET(fdr,&rdset) )
			{
				bzero(buf,sizeof(buf));
				read(fdr,buf,sizeof(buf));
				printf("a:%s\n",buf);
			}
		}
	}
	close(fdw);
	close(fdr);
	return 0;
}
