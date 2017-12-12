#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void drop_last(char *buf)
{
	char *p=buf;
	while(*p!='\0')
	{
		p++;
	}
	while(*p!=':')
	{
		p--;
	}
	*p='\0';
}
int main(int argc,char **argv)
{
	struct stat s;
	memset(&s,0,sizeof(struct stat));
	int ret = stat(argv[1],&s);
	char *p = ctime(&(s.st_mtime));
	printf("%s\n",p);
	drop_last(p);
	char str[128];
	strcpy(str,p+4);
	printf("%ld %ud %ld %5d %5d %ld %s %s\n",s.st_ino,s.st_mode,s.st_nlink,s.st_uid,s.st_gid,s.st_size,str,argv[1]);
	return 0;
}
