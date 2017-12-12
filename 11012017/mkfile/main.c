#include<stdio.h>
int main(int argc,int **argv)
{
	int sum;
	int i=atoi(argv[1]);
	int j=atoi(argv[2]);
	sum=add(i,j);
	printf("sum=%d\n",sum);
	return 1;
}
