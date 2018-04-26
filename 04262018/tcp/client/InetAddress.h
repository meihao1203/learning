 ///
 /// @file    InetAddress.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 11:49:30
 ///
 
#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__
#include<iostream>
#include<netinet/in.h>
#include<string>
using namespace std;
namespace meihao
{
	class InetAddress
	{
		public:
			InetAddress(unsigned short);
			InetAddress(const string&,unsigned short);
			InetAddress(struct sockaddr_in);
			const struct sockaddr_in* getInetAddressPtr()const;
			string ip();
			unsigned short port();
		private:
			struct sockaddr_in _addr;
	};
};
#endif
