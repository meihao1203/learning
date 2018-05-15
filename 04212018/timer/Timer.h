 ///
 /// @file    Timer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 10:38:51
 ///
 
#ifndef __TIMER_H__
#define __TIMER_H__
#include<iostream>
#include<functional>
#include"Noncopyable.h"
using namespace std;
namespace meihao
{
	class Timer:Noncopyable
	{
		typedef ::function<void()> TimerCallback;
		public:
			Timer(TimerCallback,int,int);
			void start();
			void stop();
			virtual ~Timer();
		private:
			int _fd;  // 用来接收timerfd
			bool _isStarted;
			TimerCallback _cb;  // timerfd触发后执行什么函数
			int _initialSec;   // 初始时间
			int _intervalSec;  // 间隔时间
	};
};
#endif
