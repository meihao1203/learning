#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
	if(3!=argc)
	{
		fputs("error args\n",stderr);
		return -1;
	}
	char buf[128]="hello world\n";
	int fdw = open(argv[1],O_CREAT|O_WRONLY,0666);
	if( -1==fdw )
	{
		fputs("error open\n",stderr);  //perror(open);
		return -1;
	}
	printf("fdw =%d\n",fdw);
	int ret = write(fdw,buf,strlen(buf));
	if( 0>=ret )
	{
		perror("write");
		return -1;
	}
	printf("write ret=%d\n",ret);
	int fdr = open(argv[2],O_CREAT|O_RDONLY,0666);
	if( -1==fdr )
	{
		fputs("error open\n",stderr);  //perror(open);
		return -1;
	}
	printf("fdr =%d\n",fdr);
	bzero(buf,0);
	ret = read(fdr,buf,sizeof(buf));
	printf("read ret=%d\n",ret);
	close(fdw);
	close(fdr);
}
