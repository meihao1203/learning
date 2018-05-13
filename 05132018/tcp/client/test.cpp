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
#include"SocketIO.h"
using namespace std;
void test0()
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	meihao::InetAddress inetaddr("192.168.254.136",8848);  // 所以这个也能链接上
	int ret = connect(sfd,(const struct sockaddr*)inetaddr.getInetAddressPtr(),(socklen_t)sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		_exit(-1);
	}
	meihao::SocketIO socketio(sfd);
	char buf[512];
	socketio.readline(buf,sizeof(buf));
	cout<<buf<<endl;
	bzero(buf,sizeof(buf));
	read(0,buf,sizeof(buf));
	socketio.writen(buf,sizeof(buf));
#if 1
	while(true)
	{
	}
#endif
}
void test1()
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	meihao::InetAddress inetaddr("192.168.254.136",8848);  // 所以这个也能链接上
	int ret = connect(sfd,(const struct sockaddr*)inetaddr.getInetAddressPtr(),(socklen_t)sizeof(struct sockaddr));
	meihao::SocketIO socketio(sfd);
	char buf[512] = "";
	socketio.readline(buf,sizeof(buf));
	cout<<buf;
	bzero(buf,sizeof(buf));
	read(0,buf,sizeof(buf));
	socketio.writen(buf,sizeof(buf));

	bzero(buf,sizeof(buf));
	socketio.readline(buf,sizeof(buf));
	cout<<buf<<endl;
	
	::shutdown(sfd,SHUT_WR);
}

int main()
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	meihao::InetAddress inetaddr("192.168.254.136",8848); 
	int ret = connect(sfd,(const struct sockaddr*)inetaddr.getInetAddressPtr(),(socklen_t)sizeof(struct sockaddr));
	cout<<ret<<endl;
	meihao::SocketIO socketio(sfd);
	char buf[512] = "";
	socketio.readline(buf,sizeof(buf));
	cout<<buf;
	bzero(buf,sizeof(buf));
	read(0,buf,sizeof(buf));
	socketio.writen(buf,sizeof(buf));
	bzero(buf,sizeof(buf));
	socketio.readline(buf,sizeof(buf));
	cout<<buf<<endl;
	::shutdown(sfd,SHUT_WR);
}

