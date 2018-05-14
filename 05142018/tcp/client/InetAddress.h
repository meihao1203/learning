 ///
 /// @file    InetAddress.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-06 19:48:08
 ///
 
#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__
#include<iostream>
#include<netinet/in.h>
using namespace std;
namespace meihao
{
	class InetAddress
	{
		public:
			InetAddress(unsigned short port);
			InetAddress(const string& ip,unsigned short port);
			InetAddress(struct sockaddr_in addr);
			const struct sockaddr_in* getInetAddressPtr();
			string ip()const;
			unsigned short port()const;
		private:
			struct sockaddr_in _addr;
	};
};
#endif
