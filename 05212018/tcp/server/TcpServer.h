 ///
 /// @file    TcpServer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 15:42:17
 ///
	
#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__
#include<iostream>
#include"Socket.h"
#include"EpollPoller.h"
#include"TcpConnection.h"
#include"InetAddress.h"
using namespace std;
namespace meihao
{
	class TcpServer
	{
		public:
			TcpServer(unsigned short port);
			TcpServer(const char* ip,unsigned short port);
			void start();
			void stop();
			void setConnectionCallback(TcpConnectionCallback);
			void setMessageCallback(TcpConnectionCallback);
			void setCloseCallback(TcpConnectionCallback);
		private:
			InetAddress _addr;
			Socket _sock;
			EpollPoller _epoll;
			TcpConnectionCallback _onConnection;
			TcpConnectionCallback _onMessage;
			TcpConnectionCallback _onClose;
	};
};
#endif
