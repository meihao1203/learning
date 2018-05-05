///
/// @file    Socket.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-05-04 16:09:48
///

#include"Socket.h"
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define handle_error(msg) \
	do{\
		perror(msg);\
		_exit(-1);\
	}while(0)
namespace meihao
{
	int getSocketFd()
	{
		int fd = socket(AF_INET,SOCK_STREAM,0);
		if(-1==fd)
		{
			perror("socket");
			_exit(-1);
		}
		return fd;
	}
	Socket::Socket():_fd(getSocketFd())
	{
	}
	Socket::Socket(int fd):_fd(fd)
	{
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
		int retFd = ::accept(_fd,NULL,NULL);
		if(-1==retFd)
		{
			perror("accept");
			_exit(-1);
		}
		return retFd;
	}
	void Socket::shutdownWrite()
	{
		int ret = ::shutdown(_fd,SHUT_WR);   // 服务器端不再写数据
		if(-1==ret)
		{
			handle_error("shutdown");
		}
	}
	int Socket::fd()
	{
		return _fd;
	}
	InetAddress Socket::getLocalAddress(int fd)
	{
		struct sockaddr_in addr;
		memset(&addr,0,sizeof(addr));
		socklen_t addrlen;
		int ret = ::getsockname(fd,(struct sockaddr*)&addr,&addrlen);
		if(-1==ret)
		{
			handle_error("getsockname");
		}
		return InetAddress(addr);
	}
	InetAddress Socket::getPeerAddress(int fd)
	{
		struct sockaddr_in addr;
		memset(&addr,0,sizeof(addr));
		socklen_t addrlen;
		int ret = ::getpeername(fd,(struct sockaddr*)&addr,&addrlen);
		if(-1==ret)
		{
			handle_error("getpeername");
		}
		return InetAddress(addr);
	}
	void Socket::setReuseAddr(bool on)
	{//地址复用，负载均衡
		int val = on?1:0;
		int ret = ::setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,(const char*)&val,sizeof(int));
		if(-1==ret)
		{
			handle_error("setsockopt");
		}
	}
	void Socket::setReusePort(bool on)
	{//端口复用，负载均衡
		int val = on?1:0;
		int ret = ::setsockopt(_fd,SOL_SOCKET,SO_REUSEPORT,(const char*)&val,sizeof(int));
		if(-1==ret)
		{
			handle_error("setsockopt");
		}
	}
	void Socket::bind(const InetAddress& addr)
	{
		int ret = ::bind(_fd,(const struct sockaddr*)&addr,sizeof(addr));
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
};

