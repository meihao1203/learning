 ///
 /// @file    clientTest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 17:04:00
 ///
 
#include<iostream>
#include"InetAddress.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;
int main()
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	//下面两个都能连接到服务器端，127.0.0.1是本地环回测试地址
	//127.0.0.1~127.255.255.254时间的任意地址
	//meihao::InetAddress inetaddr(8888);  // 使用这个ip=127.0.0.1
	//meihao::InetAddress inetaddr("192.168.254.136",8888);
	meihao::InetAddress inetaddr("127.1.1.1",8888);  // 所以这个也能链接上
	int ret = connect(sfd,(const struct sockaddr*)inetaddr.getInetAddressPtr(),(socklen_t)sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		_exit(-1);
	}
	char buf[512];
	recv(sfd,buf,sizeof(buf),0);
	cout<<"recv:"<<buf<<endl;
	memset(buf,0,sizeof(buf));
	strcpy(buf,"I am client!");
	write(sfd,buf,sizeof(buf));
	return 0;
}
//recv:hello,world
