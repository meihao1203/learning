 ///
 /// @file    InetAddress.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 15:19:13
 ///
 
#include"InetAddress.h"
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;
namespace meihao
{
	InetAddress::InetAddress(unsigned short port)
	{
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = INADDR_ANY;
	}
	InetAddress::InetAddress(const char* ip,unsigned short port)
	{
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = inet_addr(ip);
	}
	InetAddress::InetAddress(const struct sockaddr_in& addr)
	{
		_addr = addr;
	}
	struct sockaddr_in* InetAddress::getInetAddressPtr()
	{
		&_addr;
	}
	string InetAddress::ip()const
	{
		return inet_ntoa(_addr.sin_addr);
	}
	unsigned short InetAddress::port()const
	{
		return ntohs(_addr.sin_port);
	}
};
