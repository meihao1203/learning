 ///
 /// @file    TimerThread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 11:39:59
 ///
 
#ifndef __TIMERTHREAD_H__
#define __TIMERTHREAD_H__
#include<iostream>
#include"Noncopyable.h"
#include"Thread.h"
#include"Timer.h"
using namespace std;
namespace meihao
{
	class TimerThread:Noncopyable
	{
		typedef function<void()> TimerCallback;
		public:
			TimerThread(TimerCallback,int,int);
			void start();
			void stop();
		private:
			Thread _thread;
			Timer _timer;
	};
};
#endif
