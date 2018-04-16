 ///
 /// @file    Condition.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 16:54:22
 ///
 
#ifndef __CONDITION_H__
#define __CONDITION_H__
#include<iostream>
#include"Noncopyable.h"
#include<pthread.h>
using namespace std;
namespace meihao
{
	class MutexLock;
	class Condition:private Noncopyable
	{
		public:
			Condition(MutexLock& mutex):_mutex(mutex)
			{
				pthread_cond_init(&_cond,NULL);
			}
			~Condition();
			void wait();
			void notify();
			void notifyall();
		private:
			pthread_cond_t _cond;
			MutexLock& _mutex;
	};
};
#endif
