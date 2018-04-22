 ///
 /// @file    server.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-22 16:01:00
 ///
 
#include<sys/types.h>
#include<sys/socket.h>
#include<iostream>
#include<stdio.h>
#include<errno.h>
#include<strings.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
using namespace std;
int main()
{
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	// 这里不传IP和端口号了，直接使用本机IP，写死端口号
	struct sockaddr_in serverAddr;
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8888);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	int ret = bind(sfd,(const struct sockaddr*)&serverAddr,sizeof(serverAddr));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	ret = listen(sfd,10);
	if(-1==ret)
	{
		perror("listen");
		return 0;
	}
	int connectFd = accept(sfd,NULL,NULL);
	char buf[1024] = "this is server";
	write(connectFd,buf,strlen(buf));
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(connectFd,buf,1024);  // 都是描述符，read和recv都一样
		write(connectFd,buf,strlen(buf));
	}
	return 0;
}
