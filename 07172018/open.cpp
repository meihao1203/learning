 ///
 /// @file    open.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-17 21:21:41
 ///
 
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(int argc,char** argv)
{
	int fdw = open(argv[1],O_CREAT|O_WRONLY|O_APPEND,0666);
	write(fdw,"meihao\n",7);
	close(fdw);
	return 0;
}
