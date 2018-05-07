 ///
 /// @file    SocketIO.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-07 10:34:42
 ///
 
#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__
#include<iostream>
using namespace std;
namespace meihao
{
	class SocketIO
	{
		public:
			SocketIO(int fd);
			int readn(char* buf,int count);
			int writen(const char* buf,int count);
			int readline(char* buf,int maxlen);
		private:
			int recvPeek(char* buf,int count);  // 预读取一行
		private:
			int _fd;
	};
};
#endif
