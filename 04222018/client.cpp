 ///
 /// @file    client.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-22 16:49:30
 ///
 
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;
int main()
{
	int peerfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==peerfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in clientAddr;
	bzero(&clientAddr,sizeof(clientAddr));
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_addr.s_addr = INADDR_ANY;
	clientAddr.sin_port = htons(8888);
	int ret = connect(peerfd,(struct sockaddr*)&clientAddr,sizeof(clientAddr));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	char buf[1024];
	read(peerfd,buf,sizeof(buf));
	printf("%s\n",buf);
	while(1)
	{
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		write(peerfd,buf,sizeof(buf));
		read(peerfd,buf,sizeof(buf));
		cout<<"recv "<<buf<<endl;
	}
	return 0;
}
//this is server
//hello
//recv hello
//
//world
//recv world
//
//^C
