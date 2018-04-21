 //
 /// @file    Thread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 09:58:04
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include<iostream>
#include"Noncopyable.h"
#include<pthread.h>
#include<functional>
using namespace std;
namespace meihao
{
	class Thread:Noncopyable
	{
		typedef ::function<void()> ThreadCallback;
		public:
			Thread(ThreadCallback);
			void start();
			void join();
			static void* threadFunc(void*);
			virtual ~Thread();
		private:
			pthread_t _pthId;
			bool _isRunning;
			ThreadCallback _cb;
	};
};
#endif
