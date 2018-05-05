 ///
 /// @file    TcpConnection.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 20:51:59
 ///
 
#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__
#include<iostream>
#include"Socket.h"
#include"SocketIO.h"
#include"InetAddress.h"
using namespace std;
namespace meihao
{
	class TcpConnection
	{
		public:
			TcpConnection(int connectfd);
			~TcpConnection();
			string receive();
			void send(const string& msg);
			void shutdown();
			string toString()const;  // 返回服务端IP、port和客户端IP、port
		private:
			Socket _sock;
			SocketIO _sockIO;
			InetAddress _localAddress;
			InetAddress _peerAddress;
			bool _isShutdownWrite;
	};
};
#endif
