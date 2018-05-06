 ///
 /// @file    fgets.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 16:50:15
 ///
 
// 测试read和fgets会读到\n
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
using namespace std;
int main()
{
	char buf[512];
	fgets(buf,sizeof(buf),stdin);
	cout<<"get buf size:"<<strlen(buf)<<endl;
	for(int i=0;i<strlen(buf);i++)
	{
		printf("%d %c\n",buf[i],buf[i]);
	}
	cout<<buf<<endl;
	cout<<"-----------------------"<<endl;
	bzero(buf,sizeof(buf));
	read(0,buf,sizeof(buf));
	cout<<"get buf size:"<<strlen(buf)<<endl;
	for(int i=0;i<strlen(buf);i++)
	{
		printf("%d %c\n",buf[i],buf[i]);
	}
	cout<<buf<<endl;
	cout<<"-----------------------"<<endl;
	string tmp;
	cin>>tmp;
	cout<<"tmp size:"<<tmp.size()<<endl;
	for(int i=0;i<tmp.size();i++)
	{
		printf("%d %c\n",tmp[i],tmp[i]);
	}
	cout<<tmp<<endl;
}
//mei
//get buf size:4
//109 m
//101 e
//105 i
//10 
//
//mei
//
//-----------------------
//hao
//get buf size:4
//104 h
//97 a
//111 o
//10 
//
//hao
//
//-----------------------
//qwe
//tmp size:3
//113 q
//119 w
//101 e
//qwe
