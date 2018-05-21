 ///
 /// @file    TcpServer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 15:55:04
 ///
 
#include"TcpServer.h"
#include<iostream>
using namespace std;
namespace meihao
{
	TcpServer::TcpServer(unsigned short port):_addr(port)
											,_sock()
											,_epoll(_sock.fd())
	{//建立TCPServer对象的时候就开始监听
		_sock.ready(_addr);
	}
	TcpServer::TcpServer(const char* ip,unsigned short port):_addr(ip,port)
															,_sock()
															,_epoll(_sock.fd())
	{
		_sock.ready(_addr);
	}
	void TcpServer::start()
	{
		_epoll.setConnectionCallback(_onConnection);
		_epoll.setMessageCallback(_onMessage);
		_epoll.setCloseCallback(_onClose);
		_epoll.loop();  // 设置好回调函数后开始监听客户端请求
	}
	void TcpServer::stop()
	{
		_epoll.unloop();
	}
	void TcpServer::setConnectionCallback(TcpConnectionCallback cb)
	{
		_onConnection = cb;
	}
	void TcpServer::setMessageCallback(TcpConnectionCallback cb)
	{
		_onMessage = cb;
	}
	void TcpServer::setCloseCallback(TcpConnectionCallback cb)
	{
		_onClose = cb;
	}
};
