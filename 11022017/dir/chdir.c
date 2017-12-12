#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	char *p=NULL;
	p = getcwd(NULL,0);
	printf("p=%s\n",p);
	int ret=chdir(argv[1]);
	if(0!=ret)
	{
		perror("chdir");
		return -1;
	}
	p = getcwd(NULL,0);
	printf("after chdir p=%s\n",p);
	return 0;
}
