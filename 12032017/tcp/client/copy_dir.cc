/*************************************************************************
  > File Name: copy_dir.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Tue 03 Mar 2015 09:37:20 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
void copy_dir_core(char* src, char* dest);
void copy_dir(char* src, char* dest);
void copy_file(char* src,   char* dest);
int main(int argc, char* argv[]) //src dest
{
	copy_dir(argv[1], argv[2]);	
	return 0 ;
}

void copy_file(char* src, char* dest)
{
	int fd_dest = open(dest, O_WRONLY | O_CREAT, 0666);
	int fd_src = open(src, O_RDONLY);
	if(fd_dest == -1 || fd_src == -1)
	{
		perror("open file");
		exit(1);
	}
	char buf[1024] ;
	while(memset(buf, 0, 1024), read(fd_src, buf, 1023) != 0)
	{
		write(fd_dest, buf, strlen(buf));
	}
	close(fd_src);
	close(fd_dest);
}
void copy_dir(char* src, char* dest)
{
	char dest_path[1024] = "" ;
	sprintf(dest_path, "%s/%s", dest, src);
	if(mkdir(dest_path, 0777) == -1)
	{
		perror("mkdir");
		exit(1);
	}
	copy_dir_core(src, dest_path);

}
void copy_dir_core(char* src, char* dest)
{
	DIR* psrc = opendir(src);
	char src_path[1024] = "" ;
	char dest_path[1024] = "" ;
	if(psrc == NULL)
	{
		perror("open dir");
	}
	struct dirent* pent ;
	struct stat mystat ;
	while( (pent = readdir(psrc)) != NULL)
	{
		if(strcmp(pent ->d_name, ".") == 0 || strcmp("..", pent ->d_name) == 0)
		{
			continue ;
		}
		memset(&mystat, 0, sizeof(mystat));
		memset(src_path, 0, 1024);
		sprintf(src_path, "%s/%s", src, pent ->d_name);
		if(-1 == lstat( src_path,&mystat))
		{
			perror("stat");
			exit(1);
		}
		if(S_ISREG(mystat.st_mode))
		{
			memset(dest_path, 0, 1024);
			sprintf(dest_path, "%s/%s", dest, pent->d_name);
			copy_file(src_path, dest_path);
		}else if(S_ISDIR(mystat.st_mode))
		{
			memset(dest_path, 0, 1024);
			sprintf(dest_path, "%s/%s", dest, pent->d_name);
			printf("dest_dir : %s\n", dest_path);
			if(mkdir(dest_path, 0777) == -1)
			{
				perror("mkfifo");
				exit(1);
			}
			copy_dir_core(src_path, dest_path);
		}else 
		{
			continue ;
		}

	}
	closedir(psrc);

}
