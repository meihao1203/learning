#include"func.h"
int is_file_exist(char *filename)
{
	char *pwd = getcwd(NULL,0);
	DIR *dir = opendir(pwd);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;  //means fail
	}
	struct dirent *q = NULL;
	while((q=readdir(dir))!=NULL)
	{
		if(strcmp(q->d_name,filename)==0)
		{
			return 0;
		}
	}
	return -1;
}