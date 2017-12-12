#include<head.h>
int main(int argc,char ** argv)
{
	int ret = open(argv[1],O_CREAT|O_RDONLY,0666);
	printf("ret = %d\n",ret);
	close(ret);
	return 0;
}
