#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
#include<string.h>
int main(int argc,char **argv)
{
	int fd = open(argv[1],O_RDWR);
	struct stat buf;
	bzero(&buf,sizeof(struct stat));
	fstat(fd,&buf);
	char *p = (char *)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	printf("p=%s\n",p);
	char tmp[5]="world";
	for(int i=0;i<strlen(tmp);i++)
	{
		p[i]=tmp[i];
	}
	printf("------after change------\n%s\n",p);
	munmap(NULL,buf.st_size);
	return 0;
}
