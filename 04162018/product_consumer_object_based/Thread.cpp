 ///
 /// @file    Thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 16:28:16
 ///
 
#include<iostream>
#include"Thread.h"
using namespace std;
namespace meihao
{
	Thread::~Thread()
	{
		pthread_detach(_pthId);
	}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);  // 调用成员函数的this指针也要传递过去
		_isRunning = true;
	}
	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
			_isRunning = false;
		}
	}
	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread = static_cast<Thread*> (arg);
		if(NULL!=pthread)
		{
			pthread->_cb();
		}
	}
};
