 ///
 /// @file    MutexLock.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 09:50:53
 ///
 
#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__
#include<iostream>
using namespace std;
class MutexLock
{
	public:
		MutexLock()
		{
			cout<<"MutexLock()"<<endl;
			pthread_mutex_init(&_mutex,NULL);
		}
		~MutexLock()
		{
			cout<<"~MutexLock()"<<endl;
			pthread_mutex_destroy(&_mutex);
		}
		void lock()
		{
			pthread_mutex_lock(&_mutex);
		}
		void unlock()
		{
			pthread_mutex_unlock(&_mutex);
		}
		pthread_mutex_t* getMutexPtr()
		{
			return &_mutex;
		}
	private:
		pthread_mutex_t _mutex;
};
#endif
