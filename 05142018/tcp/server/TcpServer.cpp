 ///
 /// @file    TcpServer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-13 20:54:20
 ///
 
#include"TcpServer.h"
#include<iostream>
using namespace std;
namespace meihao
{
	TcpServer::TcpServer(unsigned short port):_addr(port)
											,_serverSock()
										    ,_epoll(_serverSock.fd())
	{
	}
	TcpServer::TcpServer(const string& ip,unsigned short port):_addr(ip,port)
															,_serverSock()
															,_epoll(_serverSock.fd())
	{
	}
	TcpServer::TcpServer(const InetAddress& addr):_addr(addr)
												,_serverSock()
											    ,_epoll(_serverSock.fd())
	{
	}
	void TcpServer::start()
	{
		_serverSock.ready(_addr);  // 开启服务器，并监听
		//epoll类设置请求的tcp连接的回调函数
		_epoll.epollSetConnectionCallback(_onConnectionCb); 
		_epoll.epollSetMessageCallback(_onMessageCb);
		_epoll.epollSetCloseCallback(_onCloseCb);
		_epoll.loop();  // epoll_wait客户端连接请求
	}
	void TcpServer::stop()
	{
		_epoll.unloop();
		_serverSock.shutdownWrite();
	}
	void TcpServer::tcpServerSetConnectionCallback(TcpConnectionCallback cb)
	{
		_onConnectionCb = cb;
	}
	void TcpServer::tcpServerSetMessageCallback(TcpConnectionCallback cb)
	{
		_onMessageCb = cb;
	}
	void TcpServer::tcpServerSetCloseback(TcpConnectionCallback cb)
	{
		_onCloseCb = cb;
	}
};
