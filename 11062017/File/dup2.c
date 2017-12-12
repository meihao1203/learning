#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
int main(int argc,char **argv)
{
	int fda = open(argv[1],O_RDONLY);
	int fdb = open(argv[2],O_RDONLY);
	printf("before dup fda=%d fdb=%d\n",fda,fdb);
	int fdaa = dup(fda);
	printf("dup fda=%d fdaa=%d\n",fda,fdaa);
	int fdup2b = dup2(fdb,fdaa);
	printf("dup2 fdb=%d fdaa=%d fdup2b=%d\n",fdb,fdaa,fdup2b);
	char buf[32];
	read(fda,buf,sizeof(buf));
	printf("fda read buf=%s\n",buf);
	bzero(buf,sizeof(buf));
	read(fdb,buf,sizeof(buf));
	printf("fdb read buf=%s\n",buf);
	lseek(fda,0,SEEK_SET);
	lseek(fdb,0,SEEK_SET);
	bzero(buf,sizeof(buf));
	read(fdaa,buf,sizeof(buf));
	printf("fdaa read buf=%s\n",buf);
	lseek(fdaa,0,SEEK_SET);
	bzero(buf,sizeof(buf));
	read(fdup2b,buf,sizeof(buf));
	printf("fdup2b read buf=%s\n",buf);
	return 0;
}
