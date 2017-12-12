#include<stdio.h>
#include<unistd.h>
int main()
{
	char *a[]={"./add","1","2",NULL};
	printf("ee\n");
	//execl("./add","add","1","2",NULL);
	int ret = execv("./add",a);
	if(-1==ret)
	{
		perror("execl");	
		return -1;
	}
	printf("I am execl\n");
	return 0;
}