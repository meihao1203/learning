 ///
 /// @file    getcwd.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-12 14:58:01
 ///
 
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char* path = getcwd(NULL,0);
	printf("%s\n",path);
	free(path);
	path = NULL;
}
