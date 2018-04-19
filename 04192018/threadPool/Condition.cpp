 ///
 /// @file    Condition.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 10:23:47
 ///
 
#include"Condition.h"
#include<iostream>
using namespace std;
namespace meihao
{
	Condition::Condition(MutexLock& mutex):_mutex(mutex)
	{
		pthread_cond_init(&_cond,NULL);
	}
	Condition::~Condition()
	{
		pthread_cond_destroy(&_cond);
	}
	void Condition::wait()
	{
		pthread_cond_wait(&_cond,_mutex.getMutexPtr());
	}
	void Condition::notify()
	{
		pthread_cond_signal(&_cond);
	}
	void Condition::notifyall()
	{
		pthread_cond_broadcast(&_cond);
	}
};
