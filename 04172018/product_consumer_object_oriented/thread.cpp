 ///
 /// @file    thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-17 09:57:19
 ///
 
#include<iostream>
#include"thread.h"
using namespace std;
namespace meihao
{
	Thread::Thread():_pthId(0),_isRunning(false){}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);
		_isRunning = true;
	}
	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
		}
	}
	Thread::~Thread()
	{
		pthread_detach(_pthId);
	}
	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread = static_cast<Thread*> (arg);
		if(NULL!=pthread)
		{
			pthread->run();
		}
	}
};
