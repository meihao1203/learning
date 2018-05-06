 ///
 /// @file    Socket.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 20:35:16
 ///
 
#ifndef __SOCKET_H__
#define __SOCKET_H__
#include<iostream>
#include"InetAddress.h"
using namespace std;
namespace meihao
{
	class Socket
	{
		public:
			Socket();
			Socket(int fd);
			void ready(const InetAddress& addr);
			int accept();
			void shutdownWrite();
			int fd();
			static InetAddress getLocalAddress(int fd);
			static InetAddress getPeerAddress(int fd);
		private:
			void setReuseAddr(bool on);
			void setReusePort(bool on);
			void bind(const InetAddress& addr);
			void listen();
		private:
			int _fd;
	};
};
#endif
