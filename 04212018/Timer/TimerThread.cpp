 ///
 /// @file    TimerThread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 11:51:12
 ///
 
#include<iostream>
#include"TimerThread.h"
using namespace std;
namespace meihao
{
	TimerThread::TimerThread(TimerCallback cb,int initialSec,int intervalSec):_timer(cb,initialSec,intervalSec)
																 ,_thread(::bind(&Timer::start,&_timer))
	{

	}
	void TimerThread::start()
	{
		_thread.start();
	}
	void TimerThread::stop()
	{
		_timer.stop();
		_thread.join();
	}
};
