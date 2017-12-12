#include<stdio.h>
#include<stdlib.h>
void main(int argc , char **argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return;
	}
	int i=atoi(argv[1]);
	int j=atoi(argv[2]);
	printf("sum=%d\n",add(i,j));
}
