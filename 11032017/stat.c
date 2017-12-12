#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<pwd.h>
#include<grp.h>
void change_time_type(char *t)
{
	char *p;
	p=t+strlen(t)-1;
	while( *p != ':' )
	{
		p--;
	}
	*p='\0';
}
int main(int argc,char **argv)
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	struct stat buf;
	memset(&buf,0,sizeof(buf));
	int ret = stat(argv[1],&buf);
	if(-1==ret)
	{
		perror("stat");
		return -1;
	}
	char t[128];
	strcpy(t,ctime(&buf.st_mtime));
	change_time_type(t);
	printf("%5x %ld %s %s %ld %s %s\n",buf.st_mode, buf.st_nlink, getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name, buf.st_size, t+4, argv[1]);
	return 0;
}
