 ///
 /// @file    InetAddress.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 15:42:45
 ///
 
#include"InetAddress.h"
#include<iostream>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;
namespace meihao
{
	InetAddress::InetAddress(string ip,unsigned short port)
	{
		memset(&_addr,0,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	}
	InetAddress::InetAddress(unsigned short port)
	{
		memset(&_addr,0,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = INADDR_ANY;
	}
	InetAddress::InetAddress(struct sockaddr_in addr)
	{
		_addr = addr;
	}
	const struct sockaddr_in* InetAddress::getInetAddressPtr()
	{
		return &_addr;
	}
	string InetAddress::ip()const
	{
		string(inet_ntoa(_addr.sin_addr));
	}
	unsigned short InetAddress::port()const
	{
		_addr.sin_port;
	}
};
