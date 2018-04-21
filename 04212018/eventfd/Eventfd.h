 ///
 /// @file    Eventfd.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 15:38:19
 ///
 
#ifndef __EVENTFD_H__
#define __EVENTFD_H__
#include<iostream>
#include<functional>
using namespace std;
namespace meihao
{
	class Eventfd
	{
		typedef std::function<void()> EventfdCallback;
		public:
			Eventfd(EventfdCallback);
			void start();
			void wakeup();  // 用eventfd写数据，唤醒一个等待用描述符读数据的操作 
			void handleRead();  // 读走计数器上的数据
			void stop();  // 停止循环读操作
			~Eventfd();
		private:
			int _fd;
			bool _isStarted;
			EventfdCallback _cb;
	};
};
#endif
