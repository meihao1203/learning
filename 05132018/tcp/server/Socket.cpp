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
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
using namespace std;
#define handle_error(msg) \
	do{\
		perror(msg);\
	exit(-1);\
	}while(0);
namespace meihao
{
	int getSocketfd()
	{
		int sfd = socket(AF_INET,SOCK_STREAM,0);
		if(-1==sfd)
		{
			handle_error("socket");
		}
	}
	Socket::Socket():_fd(getSocketfd())
	{
	}
	Socket::Socket(int fd):_fd(fd)
	{
	}
	void Socket::setReuseAddr(bool on)
	{
		int val = on?1:0;
		int ret = setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,(const void*)&val,sizeof(int));
		if(-1==ret)
		{
			handle_error("setsockopt");
		}
	}
	void Socket::setReusePort(bool on)
	{
		int val = on?1:0;
		int ret = setsockopt(_fd,SOL_SOCKET,SO_REUSEPORT,(const void *)&val,sizeof(int));
		if(-1==ret)
		{
			handle_error("setsockopt");
		}
	}
	void Socket::bind(const InetAddress& addr)
	{
		int ret = ::bind(_fd,(const struct sockaddr*)&addr,(socklen_t)sizeof(addr));
		if(-1==ret)
		{
			handle_error("::bind");
		}
	}
	void Socket::listen()
	{
		int ret = ::listen(_fd,10);
		if(-1==ret)
		{
			handle_error("::listen");
		}
	}
	void Socket::ready(const InetAddress& addr)
	{
		setReuseAddr(true);
		setReusePort(true);
		bind(addr);
		listen();
	}
	int Socket::accept()
	{
		int new_fd = ::accept(_fd,NULL,NULL);
		if(-1==new_fd)
		{
			handle_error("::accept");
		}
	}
	void Socket::shutdownWrite()
	{
		int ret = ::shutdown(_fd,SHUT_WR);
		if(-1==ret)
		{
			handle_error("::shutdown");
		}
	}
	int Socket::fd()
	{
		return _fd;
	}
	InetAddress Socket::getLocalAddress(int fd)
	{
		struct sockaddr_in addr;
		bzero(&addr,sizeof(addr));
		int addrlen = sizeof(addr);
		int ret = ::getsockname(fd,(struct sockaddr*)&addr,(socklen_t*)&addrlen);
		if(-1==ret)
		{
			handle_error("::getsockname");
		}
		return InetAddress(addr);
	}
	InetAddress Socket::getPeerAddress(int fd)
	{
		struct sockaddr_in addr;
		bzero(&addr,sizeof(addr));
		int addrlen = sizeof(addr);
		int ret = ::getpeername(fd,(struct sockaddr*)&addr,(socklen_t*)&addrlen);
		if(-1==ret)
		{
			handle_error("::getpeername");
		}
		return InetAddress(addr);
	}
};
