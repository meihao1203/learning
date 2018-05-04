 ///
 /// @file    InetAddress.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 15:29:41
 ///
 
#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__
#include<string>
#include<netinet/in.h>
#include<iostream>
using namespace std;
namespace meihao
{
	class InetAddress
	{
		public:
			InetAddress(string& ip,unsigned short port);
			InetAddress(unsigned short port);
			InetAddress(struct sockaddr_in addr);
			const struct sockaddr_in* getInetAddressPtr();
			string ip();
			unsigned short port();
		private:
			struct sockaddr_in _addr;
	};
};
#endif
