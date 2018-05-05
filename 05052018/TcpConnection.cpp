 ///
 /// @file    TcpConnection.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-05 09:29:05
 ///
 
#include"TcpConnection.h"
#include<iostream>
#include<string.h>
#include<sstream>
#include"SocketIO.h"
using namespace std;
namespace meihao
{
	TcpConnection::TcpConnection(int connectfd):_sock(connectfd)
								 ,_sockIO(connectfd)
								 ,_localAddress(Socket::getLocalAddress(connectfd))
								 ,_peerAddress(Socket::getPeerAddress(connectfd))
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
		memset(buf,0,sizeof(buf));
		_sockIO.readLine(buf,sizeof(buf));
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
			_sock.shutdownWrite();
			_isShutdownWrite = true;
		}
	}	
	string TcpConnection::toString()const
	{
		stringstream oss;
		oss<<_localAddress.ip()<<" "<<_localAddress.port()
			<<"--->"
			<<_peerAddress.ip()<<" "<<_peerAddress.port()
			<<endl;
		return oss.str();
	}
};
