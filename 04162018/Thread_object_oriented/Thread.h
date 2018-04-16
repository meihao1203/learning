 ///
 /// @file    Thread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 10:10:13
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include<iostream>
#include<pthread.h>
#include"Noncopyable.h"
using namespace std;
namespace meihao
{
	class Thread:private Noncopyable
	{
		public:
			Thread();
			virtual ~Thread();
			virtual void run() = 0;
			static void* threadFunc(void*);
			void start();
			void join();
		private:
			pthread_t _pthId;
			bool _isRunning;
	};
};
#endif
