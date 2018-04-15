 ///
 /// @file    Thread.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 15:10:30
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
	typedef function<void()> ThreadCallback;  // 定义回调函数类型，最后线程真正执行的就是这个函数
	class Thread:private Noncopyable
	{
		public:
			Thread(ThreadCallback cb):_cb(cb),_pthId(0),_isRunning(false){  cout<<"Thread(ThreadCallback)"<<endl;  }
			~Thread();
			void start();
			void join();
			static void* threadFunc(void* arg);
		private:
			pthread_t _pthId;
			ThreadCallback _cb;
			bool _isRunning;
	};
};
#endif
