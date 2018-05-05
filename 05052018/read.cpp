 ///
 /// @file    read.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-05 15:17:12
 ///
 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<unistd.h>
#include<string.h>
using namespace std;
int main()
{
	char buf[512];
	cout<<sizeof(buf)<<endl;
	bzero(buf,sizeof(buf));
	while(1)
	{
		read(0,buf,sizeof(buf));  // \n读进来了
		printf("%s\n",buf);
		cout<<strlen(buf)<<endl;
		bzero(buf,sizeof(buf));
	}
}
//512
//mei
//mei
//
//4
//^C
