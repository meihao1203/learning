#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	char path[128];
	char *p=NULL;
	int ret;
	char *retp = getcwd(path,sizeof(path));
	if(NULL==retp)
	{
		perror("getcwd");
		return -1;
	}
	printf("path=%s\n",path);
	p = getcwd(NULL,0);
	printf("p=%s\n",p);
	return 0;
}
