 ///
 /// @file    Condtion.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 10:01:03
 ///
 
#ifndef __Condtion_h__
#define __Condtion_h__
#include<iostream>
#include"MutexLock.h"
using namespace std;
class Condtion
{
	public:
		Condtion()
		{
			cout<<"Condtion()"<<endl;
			pthread_cond_init(&_cond,NULL);
	    }	
		~Condtion()
		{
			cout<<"~Condtion()"<<endl;
			pthread_cond_destroy(&_cond);
		}
		void wait(MutexLock &mutex)
		{
			pthread_cond_wait(&_cond,mutex.getMutexPtr());
			mutex.unlock();   //wait操作现场会放权CPU，进入睡眠状态，unlock操作只有线程notify才会执行到
		}
		void notify()
		{
			pthread_cond_signal(&_cond);
		}
		void notifyall()
		{
			pthread_cond_broadcast(&_cond);
		}
	private:
		pthread_cond_t _cond;
};
#endif
