#include <unistd.h>
#include <stdio.h>

int main()
{
	char* argv[]={"add","1","2",NULL};
	execv("./add",argv);
	printf("I can not be here\n");
	return -1;
}
