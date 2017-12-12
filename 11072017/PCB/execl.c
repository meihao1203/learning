#include<stdio.h>
#include<unistd.h>
int main()
{
	execl("./add","add","1","2",NULL);
	printf("I am execl\n");
	return 0;
}