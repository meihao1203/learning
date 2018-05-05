 ///
 /// @file    Socket.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 16:01:16
 ///
 
#ifndef __SOCKET_H__
#define __SOCKET_H__
#include<iostream>
#include"InetAddress.h"
#include<sys/types.h>
#include<sys/socket.h>
using namespace std;
namespace meihao
{
	class Socket
	{
		public:
			Socket();
			Socket(int fd);
			void ready(const InetAddress& addr);  // 启动TCP服务器端
			int accept();
			void shutdownWrite();
			int fd();
			static InetAddress getLocalAddress(int fd);
			static InetAddress getPeerAddress(int fd);
		private:
			void setReuseAddr(bool on);  // ip地址复用
			void setReusePort(bool on);  // port端口复用
			void bind(const InetAddress& addr);
			void listen();
		private:
			int _fd;
	};
};
#endif
