 ///
 /// @file    Socket.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 16:06:41
 ///
 
#include"Socket.h"
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define handle_error(msg)\
	do{ perror(msg); exit(EXIT_FAILURE); }while(0);
namespace meihao
{
	int createFd()
	{
		int fd = ::socket(AF_INET,SOCK_STREAM,0);
		if(-1==fd)
		{
			handle_error("::socket");
		}
		return fd;
	}
	Socket::Socket():_fd(createFd())
	{
	}
	Socket::Socket(int fd):_fd(fd)
	{
	}
	void Socket::setReuseAddr(bool on)
	{
		int flag = on?1:0;
		int ret = ::setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(int));
		if(-1==ret)
		{
			handle_error("::setsockopt ADDR");
		}
	}
	void Socket::setReusePort(bool on)
	{
		int flag = on?1:0;
		int ret = ::setsockopt(_fd,SOL_SOCKET,SO_REUSEPORT,&flag,sizeof(int));
		if(-1==ret)
		{
			handle_error("::setsockopt PORT");
		}
	}
	void Socket::bind(InetAddress& addr)
	{
		int ret = ::bind(_fd,(const struct sockaddr*)(addr.getInetAddressPtr()),(socklen_t)sizeof(const struct sockaddr));
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
	void Socket::ready(InetAddress& InAddr)
	{
		setReuseAddr(true);
		setReusePort(true);
		bind(InAddr);
		listen();
	}
	int Socket::accept()
	{
		int fd = ::accept(_fd,NULL,NULL);
		if(-1==fd)
		{
			handle_error("::accept");
		}
		return fd;
	}
	int Socket::fd()
	{
		return _fd;
	}
	void Socket::shutdownWrite()
	{
		int ret = ::shutdown(_fd,SHUT_WR);
		if(-1==ret)
		{
			handle_error("::shutdown");
		}
	}
	InetAddress Socket::getLocalAddr(int fd)
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
	InetAddress Socket::getPeerAddr(int fd)
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
