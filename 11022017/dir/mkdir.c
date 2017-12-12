#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	int ret;
	ret = mkdir(argv[1],0777);
	if(0!=ret)
	{
		perror("mkdir");
		return -1;
	}
	char *p = getcwd(NULL,0);
	printf("new create dir path is: %s\n",p);
	return 0;
}
