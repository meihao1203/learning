#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<strings.h>
void traverse(const char *path,int width)
{
	DIR *dir=opendir(path);
	struct dirent *p=NULL;
	char buf[128];
	while( (p=readdir(dir))!=NULL )
	{
		if( (strcmp(p->d_name,"."))==0||(strcmp(p->d_name,".."))==0  )
		{
			continue;
		}
		if( p->d_type==4 )
		{
			bzero(buf,sizeof(buf));
			printf("%*s%s\n",width," ",p->d_name);
			bzero(buf,sizeof(buf));
			//sprintf(buf,"%s/%s",path,p->d_name);
			traverse(p->d_name,width+4);
		}
		else
		{
			printf("%*s%s\n",width," ",p->d_name);
		}
	}
}
int main(int argc,char **argv)
{
	char *path=NULL;
	path = getcwd(NULL,0);
	printf("%s\n",path);
	traverse(path,0);
	return 0;
}
