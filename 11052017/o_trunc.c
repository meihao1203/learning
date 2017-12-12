#include"head.h"
int main(int argc,char **argv)
{
	int fdr=open(argv[1],O_RDWR|O_APPEND);
	if(0>=fdr)
	{
		perror("open");
		return -1;
	}
	char buf[128];
	bzero(buf,sizeof(buf));
	int ret = read(fdr,buf,2);
	printf("read ret=%d\n",ret);
	printf("buf =%s\n",buf);
	strcat(buf,",second");
	printf("buf =%s\n",buf);
	ret = write(fdr,buf,strlen(buf));
	printf("write ret=%d\n",ret);
	close(fdr);
	return 0;
}
