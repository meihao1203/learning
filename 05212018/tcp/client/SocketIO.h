 ///
 /// @file    SocketIO.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 19:18:20
 ///
 
#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
using namespace std;
namespace meihao
{
	class SocketIO
	{
		public:
			SocketIO(int);
			int readn(char* buf,int count);
			int writen(const char* buf,int count);
			int readline(char* buf,int count);
		private:
			int readPeek(char* buf,int count);
		private:
			int _fd;
	};
};
#endif
