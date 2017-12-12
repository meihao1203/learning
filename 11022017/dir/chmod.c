#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char **argv)
{	
	if(2!=argc)
	{
		printf("error args");
		return -1;
	}
	int ret=chmod(argv[1],0777);
	if(0!=ret)
	{
		perror("chmod");
		return -1;
	}
	return 0;
}
