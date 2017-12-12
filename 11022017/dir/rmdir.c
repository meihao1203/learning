#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	int ret;
	system("ls -l");
	ret = rmdir(argv[1]);
	if(0!=ret)
	{
		perror("rmdir");
		return -1;
	}
	printf("---after rmdir---\n");
	system("ls -l");
	return 0;
}
