 ///
 /// @file    Socket.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 20:35:16
 ///
 
#ifndef __SOCKET_H__
#define __SOCKET_H__
#include<iostream>
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

		private:
			int _fd;
	};
};
#endif
