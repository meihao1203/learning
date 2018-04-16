 ///
 /// @file    Condition.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 18:04:04
 ///
 
#include<iostream>
#include"Condition.h"
#include"MutexLock.h"
using namespace std;
namespace meihao
{
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
