 ///
 /// @file    InetAddress.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 15:11:03
 ///
 
#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__
#include<iostream>
#include<arpa/inet.h>
using namespace std;
namespace meihao
{
	class InetAddress
	{
		public:
			InetAddress(unsigned short port);
			InetAddress(const char* ip,unsigned short port);
			InetAddress(const struct sockaddr_in& addr);
			struct sockaddr_in* getInetAddressPtr();
			string ip()const;
			unsigned short port()const;
		private:
			struct sockaddr_in _addr;
	};
};
#endif
