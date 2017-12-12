#include<stdio.h>
#include<stdlib.h>
int add(int a,int b)
{
	return a+b;
}
int main(int argc, char **argv)
{
	if(3!=argc)
	{	
		printf("error argcs\n");
		return -1;
	}
	int sum;
	sum=add((atoi(argv[1])),(atoi(argv[2])));
	printf("sum=%d\n",sum);
	return 1;
}
	

