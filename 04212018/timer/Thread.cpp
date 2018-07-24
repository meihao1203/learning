 ///
 /// @file    Thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 10:26:50
 ///
 
#include<iostream>
#include"Thread.h"
using namespace std;
namespace meihao
{
	Thread::Thread(ThreadCallback cb):_cb(cb)
									  ,_isRunning(false)
									  ,_pthId(0)
	{}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);
		_isRunning = true;
	}
	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning = false;
		}
	}
	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread = static_cast<Thread*> (arg);
		if(pthread)
		{
			pthread->_cb();
		}
	}
	Thread::~Thread()
	{
		pthread_join(_pthId,NULL);
	}
};
