 ///
 /// @file    TcpServer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-13 20:54:20
 ///
 
#include"TcpServer.h"
#include<iostream>
using namespace std;
namespace meihao
{
	TcpServer::TcpServer(unsigned short port):_addr(port)
											,_serverSock()
										    ,_epoll(_serverSock.fd())
	{
	}
};
