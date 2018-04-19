 ///
 /// @file    Thread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 09:47:43
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include<iostream>
#include"Noncopyable.h"
#include<pthread.h>
using namespace std;
namespace meihao
{
	class Thread:private Noncopyable
	{
		public:
			Thread();
			void start();
			void join();
			virtual void run() = 0;
			virtual ~Thread();
			static void* threadFunc(void*);
		private:
			pthread_t _pthId;
			bool _isRunning;
	};
};
#endif
