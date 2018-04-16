 ///
 /// @file    Thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 10:15:29
 ///
 
#include"Thread.h"
#include<iostream>
using namespace std;
namespace meihao
{
	Thread::Thread():_pthId(0),_isRunning(false)
	{
		cout<<"Thread()"<<endl;
	}
	Thread::~Thread()
	{
		cout<<"~Thread()"<<endl;
		if(_isRunning)
			pthread_detach(_pthId);
	}
	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread = static_cast<Thread*> (arg);
		if(NULL!=pthread)
			pthread->run();
	}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);  // 创建线程
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
};
