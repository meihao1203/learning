 ///
 /// @file    client.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-14 09:42:53
 ///
 
#include<iostream>
#include"InetAddress.h"
#include"SocketIO.h"
#include<strings.h>
#include<unistd.h>
using namespace std;
int main()
{
	meihao::InetAddress inetAddr(8848);
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	int ret = connect(sfd,(const struct sockaddr*)inetAddr.getInetAddressPtr(),sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	meihao::SocketIO socketIO(sfd);
	char buf[1024] = "";
	socketIO.readline(buf,sizeof(buf));
	cout<<buf;
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(0,buf,sizeof(buf));
		socketIO.writen(buf,sizeof(buf));
		bzero(buf,sizeof(buf));
		socketIO.readline(buf,sizeof(buf));
		cout<<"recv from server:"<<buf;
	}

}
