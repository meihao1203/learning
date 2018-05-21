 ///
 /// @file    TcpConnection.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 09:43:42
 ///
 
#include"TcpConnection.h"
#include<sstream>
#include<iostream>
using namespace std;
namespace meihao
{
	TcpConnection::TcpConnection(int fd):_sock(fd)
										,_sockIO(fd)
										,_localAddr(meihao::Socket::getLocalAddr(_sock.fd()))
										,_peerAddr(meihao::Socket::getPeerAddr(_sock.fd()))
										,_isShutdownWrite(false)
	{
	}
	TcpConnection::~TcpConnection()
	{
		if(!_isShutdownWrite)
		{
			shutdown();
		}
	}
	string TcpConnection::receive()
	{
		char buf[1024];
		_sockIO.readline(buf,sizeof(buf));
		return string(buf);
	}
	void TcpConnection::send(const string& msg)
	{
		_sockIO.writen(msg.c_str(),msg.size());
	}
	void TcpConnection::shutdown()
	{
		if(!_isShutdownWrite)
		{
			_isShutdownWrite = true;
			_sock.shutdownWrite();
		}
	}
	string TcpConnection::toString()
	{
		ostringstream oss;
		oss<<_peerAddr.ip()<<":"<<_peerAddr.port()<<"--->"
		   <<_localAddr.ip()<<":"<<_localAddr.port();
		return oss.str();
	}
	int TcpConnection::fd()
	{
		return _sock.fd();
	}
	void TcpConnection::handleConnectionCallback()
	{
		if(_onConnectionCb)
		{
			_onConnectionCb(shared_from_this());
		}
	}
	void TcpConnection::handleMessageCallback()
	{
		if(_onMessageCb)
		{
			_onMessageCb(shared_from_this());
		}
	}
	void TcpConnection::handleCloseCallback()
	{
		if(_onCloseCb)
		{
			_onCloseCb(shared_from_this());
		}
	}
	void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
	{
		_onConnectionCb = cb;
	}
	void TcpConnection::setMessageCallback(TcpConnectionCallback cb) 
	{
		_onMessageCb = cb;
	}
	void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
	{
		_onCloseCb = cb; 
	}
};
