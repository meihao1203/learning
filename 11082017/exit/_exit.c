#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	printf("Using exit...\n");
	printf("This is the content in buffer");
	_exit(0);
}