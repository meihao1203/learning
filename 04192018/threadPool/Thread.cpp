 ///
 /// @file    Thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 09:53:26
 ///
 
#include"Thread.h"
#include<iostream>
using namespace std;
namespace meihao
{
	Thread::Thread():_pthId(0),_isRunning(false)
	{
	}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);
		_isRunning = true;
	}
	void Thread::join()
	{
		if(_isRunning)
			pthread_join(_pthId,NULL);
	}
	Thread::~Thread()
	{
		if(_isRunning)
			pthread_detach(_pthId);
	}
	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread = static_cast<Thread*> (arg);
		if(NULL!=pthread)
			pthread->run();
	}
};
