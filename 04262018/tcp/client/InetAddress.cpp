 ///
 /// @file    InetAddress.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 14:49:37
 ///
 
#include"InetAddress.h"
#include<iostream>
#include<string.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;
namespace meihao
{
	InetAddress::InetAddress(unsigned short port)
	{
		memset(&_addr,0,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = port;
		_addr.sin_addr.s_addr = INADDR_ANY;  // 使用本机IP地址
	}
	InetAddress::InetAddress(const string& ip,const unsigned short& port)
	{
		memset(&_addr,0,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = port;
		_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	}
	InetAddress::InetAddress(struct sockaddr_in addr)
	{
		_addr = addr;
	}
	const struct sockaddr_in* InetAddress::getInetAddressPtr()const
	{
		return &_addr;
	}
	string InetAddress::ip()
	{
		return inet_ntoa(_addr.sin_addr);
	}
	unsigned short InetAddress::port()
	{
		return _addr.sin_port;
	}
};
