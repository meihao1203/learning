#include<stdio.h>
#include<strings.h>
int main()
{
	char buf[128]="hello , world";
	printf("buf=%s\n",buf);
	bzero(buf,sizeof(buf));
	printf("buf=%s\n",buf);
	return 1;
}
