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
void change_st_mode(char *perm,struct stat buf)
{
	
	if ((S_IFMT&buf.st_mode)==S_IFDIR )
	{
		perm[0]='d';
	}
	if( (S_ISREG(buf.st_mode)) )
	{
		perm[0]='-';
	}
	else 
	{	
		perm[0]='*';
	}
	if( (buf.st_mode & S_IRUSR)==S_IRUSR )
	{
		perm[1]='r';
	}
	if( (buf.st_mode & S_IWUSR)==S_IWUSR )
	{
		perm[2]='w';
	}
	if( (buf.st_mode & S_IXUSR)==S_IXUSR )
	{
		perm[3]='x';
	}
	if( (buf.st_mode & S_IRGRP)==S_IRGRP )
	{
		perm[4]='r';
	}
	if( (buf.st_mode & S_IWGRP)==S_IWGRP )
	{
		perm[5]='w';
	}
	if( (buf.st_mode & S_IXGRP)==S_IXGRP )
	{
		perm[6]='x';
	}
	if( (buf.st_mode & S_IROTH)==S_IROTH )
	{
		perm[7]='r';
	}
	if( (buf.st_mode & S_IWOTH)==S_IWOTH )
	{
		perm[8]='w';
	}
	if( (buf.st_mode & S_IXOTH)==S_IXOTH )
	{
		perm[9]='x';
	}
	perm[10]='\0';
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
	printf("%5x\n",buf.st_mode);
	char perm[10];
	memset(perm,'-',sizeof(perm));
	change_st_mode(perm,buf);
	printf("%s %ld %s %s %ld %s %s\n",perm, buf.st_nlink, getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name, buf.st_size, t+4, argv[1]);
	return 0;
}
