#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	printf("puid=%d pgid=%d\n",getuid(),getgid());
	printf("peuid=%d pegid=%d\n",geteuid(),getegid());
	return 0;
}