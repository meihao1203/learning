 ///
 /// @file    TcpServer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-13 20:48:40
 ///
 
#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__
#include<iostream>
#include"InetAddress.h"
#include"Socket.h"
#include"Epoll.h"
#include"TcpConnection.h"
using namespace std;
namespace meihao
{
	class TcpServer
	{
		public:
			TcpServer(unsigned short port);
			TcpServer(const string& ip,unsigned short port);
			TcpServer(const InetAddress& addr);
			void start();
			void stop();
			void tcpServerSetConnectionCallback(TcpConnectionCallback cb);
			void tcpServerSetMessageCallback(TcpConnectionCallback cb);
			void tcpServerSetCloseCallback(TcpConnectionCallback cb);
		private:
			InetAddress _addr;
			Socket _serverSock;
			Epoll _epoll;
			TcpConnectionCallback _onConnectionCb;
			TcpConnectionCallback _onMessageCb;
			TcpConnectionCallback _onCloseCb;
	};
};
#endif
