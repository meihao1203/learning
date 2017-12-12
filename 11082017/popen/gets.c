#include<stdio.h>
int main()
{	
	char buf[128];
	fread(buf,sizeof(char),sizeof(buf),stdin);
	printf("buf=%s\n",buf);
	return 0;
}