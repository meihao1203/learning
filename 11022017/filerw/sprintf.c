#include<stdio.h>
int main()
{
	char buf[128];
	int ret;
	ret=sprintf(buf,"%s %s","hello","world");
	printf("ret=%d  buf=%s\n",ret,buf);
	ret=sprintf(buf,"%d %d",1,2);
	printf("ret=%d  buf=%s\n",ret,buf);
	return 1;
}
