#include<stdio.h>
int add(int a,int b)
{
	return a+b;
}
int main(int argc,char **argv)
{
	int i,j,sum;
	i=atoi(argv[1]);
	j=atoi(argv[2]);
	sum=add(i,j);
	printf("sum=%d\n",sum);
}
