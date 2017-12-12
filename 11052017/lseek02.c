#include"head.h"
int main(int argc,char **argv)
{
	int fd = open(argv[1],O_RDWR);
	char buf[128];
	read(fd,buf,2);
	printf("buf =%s\n",buf);
	strcpy(buf,",world!");
	lseek(fd,0,SEEK_SET);
	write(fd,buf,strlen(buf));
	close(fd);
	return 0;
}
