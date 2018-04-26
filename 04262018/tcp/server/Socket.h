 ///
 /// @file    Socket.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 15:09:32
 ///
 
#ifndef __SOCKET_H__
#define __SOCKET_H__
#include<iostream>
using namespace std;
namespace meihao
{
	class InetAddress;  // 前向声明
	class Socket
	{
		public:
			Socket();  // 采用默认形式创建socket描述符
			Socket(int);  // 指定socket描述符
			void ready(const InetAddress&);
			int accept();
			void shutdownWrite();
			int fd();  // 返回socket描述符
			static InetAddress getLocalAddress(int);  // 获取服务器本地的绑定信息
			// 静态函数不能在函数后加const限定
			static InetAddress getPeerAddress(int);  // 获取连接端的ip,port信息
		private:  // 下面这些接口不对外开放
			void setReuseAddr(bool);  // 设置服务器端的ip可复用
			void setReusePort(bool);  // 设置服务器端的端口可复用
			void bind(const InetAddress&);
			void listen();
		private:
			int _fd;
	};
};
#endif
