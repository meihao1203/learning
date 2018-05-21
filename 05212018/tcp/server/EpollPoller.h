 ///
 /// @file    EpollPoller.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 10:53:35
 ///
 
#ifndef __EPOLLPOLLER_H__
#define __EPOLLPOLLER_H__
#include<iostream>
#include<sys/epoll.h>
#include"TcpConnection.h"
#include<vector>
#include<map>
using namespace std;
namespace meihao
{
	class EpollPoller
	{
		public:
			EpollPoller(int listenfd);
			void loop();
			void unloop();
			void setConnectionCallback(TcpConnectionCallback);  //设置连接到服务器端的连接的回调函数
			void setMessageCallback(TcpConnectionCallback);
			void setCloseCallback(TcpConnectionCallback);
		private:
			void waitEpollfd();
			void handleConnection();
			void handleMessage(int fd);
		private:
			int _epollfd;
			int _listenfd;
			bool _isLoop;
			vector<struct epoll_event> _eventList;
			map<int,TcpConnectionPtr> _connMap;
			TcpConnectionCallback _onConnection;
			TcpConnectionCallback _onMessage;
			TcpConnectionCallback _onClose;
	};
};
#endif
