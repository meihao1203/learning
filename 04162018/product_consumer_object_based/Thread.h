 ///
 /// @file    Thread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 16:22:47
 ///
 
#ifndef __THREAD_H__
#define __THREAD_H__
#include<iostream>
#include<pthread.h>
#include<functional>
#include"Noncopyable.h"
using namespace std;
namespace meihao
{
	typedef std::function<void()> ThreadCallback;
	class Thread:private Noncopyable
	{
		public:
			Thread(ThreadCallback cb):_pthId(0),_isRunning(false),_cb(cb){}
			~Thread();
			void start();
			void join();
			static void* threadFunc(void*);
		private:
			pthread_t _pthId;
			bool _isRunning;
			ThreadCallback _cb;
	};
};
#endif
