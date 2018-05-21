 ///
 /// @file    Socket.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 15:59:07
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
			Socket(int);
			void ready(InetAddress&);
			int accept();
			int fd();
			void shutdownWrite();
			static InetAddress getLocalAddr(int fd);
			static InetAddress getPeerAddr(int fd);
		private:
			void setReuseAddr(bool on);
			void setReusePort(bool on);
			void bind(InetAddress& addr);
			void listen();
		private:
			int _fd;
	};
};
#endif
