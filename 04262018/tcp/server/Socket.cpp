 ///
 /// @file    Socket.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 15:33:10
 ///
 
#include"Socket.h"
#include"InetAddress.h"
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
using namespace std;
namespace meihao
{
	int createSocketfd()
	{
		int sfd = socket(AF_INET,SOCK_STREAM,0);
		if(-1==sfd)
		{
			perror("socket");
			_exit(-1);
		}
		return sfd;
	}
	Socket::Socket():_fd(createSocketfd())
	{}
	Socket::Socket(int fd):_fd(fd)
	{}
	void Socket::setReuseAddr(bool on)  // 开启ip地址复用
	{  // 用了这个选项可以运行多个服务器端
		int val = on?1:0;
		if(::setsockopt(_fd,
					    SOL_SOCKET,
						SO_REUSEADDR,
						(const void*)&val,
						(socklen_t)sizeof(int))
						==-1)
		{
			perror("setsockopt");
			_exit(-1);
		}
	}
	void Socket::setReusePort(bool on)  // 开启port地址复用
	{  // 目的都是实现系统级负载均衡
		int val = on?1:0;
		if(::setsockopt(_fd,
						SOL_SOCKET,
						SO_REUSEPORT,
						(const void*)&val,
						(socklen_t)sizeof(int))
						==-1)
		{
			perror("setReusePort");
			_exit(-1);
		}
	}
	void Socket::bind(const InetAddress& addr)
	{
		if(::bind(_fd,  // 调用全局的bind
				(const struct sockaddr*)(addr.getInetAddressPtr()),
				sizeof(struct sockaddr))
				==-1)
		{
			perror("bind");
			_exit(-1);
		}
	}
	void Socket::listen()
	{
		if(::listen(_fd,
					10)  // 监听数目
					==-1)
		{
			perror("listen");
			_exit(-1);
		}
	}
	void Socket::ready(const InetAddress& addr)
	{
		//bind(addr);  // 默认局部的bind
		setReuseAddr(true);
		setReusePort(true);
		meihao::Socket::bind(addr);
		listen();
	}
	int Socket::accept()
	{
		int newfd = ::accept(_fd,NULL,NULL);
		if(-1==newfd)
		{
			perror("accept");
			_exit(-1);
		}
		return newfd;
	}
	void Socket::shutdownWrite()
	{
		if(::shutdown(_fd,SHUT_WR)==-1)   //服务器端关闭客户端
		{
			perror("shutdown");
			_exit(-1);
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
		socklen_t len = sizeof(addr);
		if(::getsockname(fd,
					    (struct sockaddr*)&addr,
						&len)
					 	==-1)
		{
			perror("getLocalAddress");
			_exit(-1);
		}
		return InetAddress(addr);
	}
	InetAddress Socket::getPeerAddress(int fd)
	{
		struct sockaddr_in addr;
		memset(&addr,0,sizeof(addr));
		socklen_t len = sizeof(addr);
		if(::getpeername(fd,
					    (struct sockaddr*)&addr,
						&len)
						==-1)
		{
			perror("getpPeerAddress");
			_exit(-1);
		}
		return InetAddress(addr);
	}
};
