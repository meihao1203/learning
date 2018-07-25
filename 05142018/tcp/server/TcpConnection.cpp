 ///
 /// @file    TcpConnection.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-07 19:11:01
 ///
 
#include"TcpConnection.h"
#include<iostream>
#include<strings.h>
#include<stdlib.h>
#include<sstream>
#include<errno.h>
#define handle_error(msg) \
	do{\
		perror(msg);\
		exit(-1);\
	}while(0);
using namespace std;
namespace meihao
{
	TcpConnection::TcpConnection(int confd):_sock(confd)
											,_sockIO(confd)
											,_localAddress(meihao::Socket::getLocalAddress(confd))
											,_peerAddress(meihao::Socket::getPeerAddress(confd))
										    ,_isShutdownWrite(false)
	{
		//剩下的回调函数使用成员函数来设置，方便使用过程中修改
	}
	TcpConnection::~TcpConnection()
	{
	}
	string TcpConnection::receive()
	{
		char buf[1024];
		bzero(buf,sizeof(buf));
		int ret = _sockIO.readline(buf,sizeof(buf));
		if(-1==ret)
		{
			handle_error("recvive");
		}
		return string(buf);
	}
	void TcpConnection::send(const string& msg)
	{
			_sockIO.writen(msg.c_str(),msg.size());
	}
	void TcpConnection::shutdown()
	{
		if(!_isShutdownWrite)  // 没有关闭
		{
			_isShutdownWrite = true;
			_sock.shutdownWrite();
		}
	}
	string TcpConnection::toString()
	{
		ostringstream oss;
		oss<<_localAddress.ip()<<" "<<_localAddress.port()<<"--->"
			<<_peerAddress.ip()<<" "<<_peerAddress.port()<<endl;
		return oss.str();
	}

	// 开始初始化类里面的回调函数的值
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

	void TcpConnection::handleConnectionCallback()
	{
		if(_onConnectionCb)
		{
			_onConnectionCb(shared_from_this());  // 传调用该函数的指针本身
			// 等价于 shared_ptr<TcpConnection>(this);
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
};
