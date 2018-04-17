 ///
 /// @file    MutexLock.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 16:13:06
 ///
 
#include<iostream>
#include"MutexLock.h"
using namespace std;
namespace meihao
{
	MutexLock::MutexLock()
	{
		pthread_mutex_init(&_mutex,NULL);
	}
	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}
	void MutexLock::lock()
	{
		pthread_mutex_lock(&_mutex);
	}
	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
	}
	pthread_mutex_t* MutexLock::getMutexPtr()
	{
		return &_mutex;
	}
};
