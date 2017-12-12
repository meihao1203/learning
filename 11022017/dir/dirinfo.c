#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc,char **argv)
{
	DIR *dir=NULL;
	dir = opendir(argv[1]);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *q=NULL;
	off_t I;
	I = telldir(dir);
	q = readdir(dir);
	I = q->d_off;
	ino_t ino = q->d_ino;
	printf("%s %ld\n",q->d_name,ino);
	while((q = readdir(dir))!=NULL)
	{
		printf("%d %s\n",q->d_type,q->d_name);
		//	I = telldir(dir);   //这里读完一次dir会自动偏到下一个位置，最后出循环的时候dir所指向的位置就不在是最后一个目录了,而是文件尾的下一个位置。
	}
	printf("-----------------------------------\n");
	//i = telldir(dir);   //得到的是文件尾的下一个位置，下面seekdir会发生段错误
	seekdir(dir,I);
	q  = readdir(dir);
	printf("%d %s\n",q->d_type,q->d_name);
	printf("-----------------------------------\n");
	rewinddir(dir);
	printf("%d %s\n",q->d_type,q->d_name);
	closedir(dir);
	return 0;
}
