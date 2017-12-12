#include<stdio.h>
int main()
{
	char buf[128]="hello , world!";
	printf("%*s%s\n",30,"!",buf);
	printf("%*s%-s\n",30," ",buf);
	//sprintf(buf,"%s%s",buf,":A");
	printf("%*s%s\n",60,buf," :A");
}