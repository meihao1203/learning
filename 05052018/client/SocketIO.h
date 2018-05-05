 ///
 /// @file    SocketIO.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 18:42:43
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
			size_t readn(char* buf,size_t count);
			size_t writen(const char* buf,size_t count);
			size_t readLine(char* buf,size_t count);  // 读一行
			size_t recvPeek(char* buf,size_t count);  // 预读取操作
		private:
			int _fd;
	};
};
#endif
