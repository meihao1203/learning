#include"head.h"
int main(int argc,char **argv)
{
	int fd = open("./c.txt",O_WRONLY);
	lseek(fd,10,SEEK_SET);
	write(fd,"a",1);
	close(fd);
	return 0;
}
