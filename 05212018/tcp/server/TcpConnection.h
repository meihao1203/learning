 ///
 /// @file    TcpConnection.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 09:26:02
 ///
 
#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__
#include<iostream>
#include<memory>
#include"Socket.h"
#include"SocketIO.h"
#include"InetAddress.h"
#include<functional>
using namespace std;
namespace meihao
{
	class TcpConnection;
	typedef ::shared_ptr<TcpConnection> TcpConnectionPtr;
	typedef ::function<void(const TcpConnectionPtr&)> TcpConnectionCallback;
	class TcpConnection:public ::enable_shared_from_this<TcpConnection>
	{
		public:
			TcpConnection(int);
			~TcpConnection();
			string receive();
			void send(const string& msg);
			void shutdown();
			string toString();
			int fd();
			void handleConnectionCallback();
			void handleMessageCallback();
			void handleCloseCallback();
			void setConnectionCallback(TcpConnectionCallback);
			void setMessageCallback(TcpConnectionCallback);
			void setCloseCallback(TcpConnectionCallback);
		private:
			Socket _sock;
			SocketIO _sockIO;
			InetAddress _localAddr;
			InetAddress _peerAddr;
			bool _isShutdownWrite;
			TcpConnectionCallback _onConnectionCb;
			TcpConnectionCallback _onMessageCb;
			TcpConnectionCallback _onCloseCb;
	};
};
#endif
