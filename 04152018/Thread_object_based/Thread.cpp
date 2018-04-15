 ///
 /// @file    Thread.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 15:22:37
 ///
 
#include"Thread.h"
#include<iostream>
using namespace std;
namespace meihao
{
	Thread::~Thread()
	{
		cout<<"~Thread()"<<endl;
		pthread_detach(_pthId);
	}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,threadFunc,this);  // 创造线程，把类对象的this指针最为参数传递给线程
		_isRunning = true;
	}
	void Thread::join()
	{
		cout<<"join()"<<endl;
		pthread_join(_pthId,NULL);  // 等待线程退出，不接受子线程返回值
		_isRunning = false;
	}
	void* Thread::threadFunc(void* pobj)
	{
		Thread* pth = static_cast<Thread*> (pobj);
		if(NULL!=pth)
		{
			pth->_cb();
		}
	}
};
