 ///
 /// @file    Socket.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 20:51:21
 ///
 
#include"Socket.h"
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
using namespace std;
#define handle_error(msg) \
	do{\
		perror(msg);\
		_exit(-1);\
		while(0);
namespace meihao
{
	int getSocketfd()
	{
		int sfd = socket(AF_INET,SOCK_STREAM,0);
		if(-1==sfd)
		{

		}
	}
	Socket::Socket()
	{

	}
};
