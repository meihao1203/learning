#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>
int main(int argc,char **argv)
{
	int fdw = open(argv[1],O_WRONLY);
	int fdr = open(argv[2],O_RDONLY);
	printf("fdw=%d\n",fdw);
	printf("fdr=%d\n",fdr);
	char buf[128];
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(0,buf,sizeof(buf));
		write(fdw,buf,strlen(buf)-1);
		bzero(buf,sizeof(buf));
		read(fdr,buf,sizeof(buf));
		printf("b:%s\n",buf);
	}
	return 0;
}
