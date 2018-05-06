 ///
 /// @file    InetAddress.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 19:54:16
 ///
 
#include"InetAddress.h"
#include<iostream>
#include<strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
namespace meihao
{
	InetAddress::InetAddress(unsigned short port)
	{
		bzero(&_addr,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = INADDR_ANY;
	}
	InetAddress::InetAddress(const string& ip,unsigned short port)
	{
		bzero(&_addr,sizeof(_addr));
		_addr.sin_family = AF_INET;
		_addr.sin_port = htons(port);
		_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	}
	InetAddress::InetAddress(struct sockaddr_in addr)
	{

	}
};
