 ///
 /// @file    MutexLock.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 10:09:18
 ///
 
#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__
#include<iostream>
#include"Noncopyable.h"
#include<pthread.h>
using namespace std;
namespace meihao
{
	class MutexLock:public Noncopyable
	{
		public:
			MutexLock();
			~MutexLock();
			void lock();
			void unlock();
			pthread_mutex_t* getMutexPtr();
		private:
			pthread_mutex_t _mutex;
	};
};
#endif
