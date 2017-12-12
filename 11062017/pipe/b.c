#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>
int main(int argc,char **argv)
{
	int fdr = open(argv[1],O_RDONLY);
	int fdw = open(argv[2],O_WRONLY);
	printf("fdr=%d\n",fdr);
	printf("fdw=%d\n",fdw);
	char buf[128];
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(fdr,buf,sizeof(buf));
		printf("a:%s\n",buf);
		bzero(buf,sizeof(buf));
		read(0,buf,sizeof(buf));
		write(fdw,buf,strlen(buf)-1);
	}
	return 0;
}
