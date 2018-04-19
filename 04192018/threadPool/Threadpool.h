 ///
 /// @file    Threadpool.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 11:46:42
 ///
 
#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include<iostream>
#include"Noncopyable.h"
#include"Task.h"
#include"Buffer.h"
#include<vector>
#include"Thread.h"
using namespace std;
namespace meihao
{
	class Threadpool:private Noncopyable
	{
		public:
			Threadpool(int,int);
			void start();
			void stop();
			void addTask(Task*);
			Task* getTask();
			void threadFunc();
		private:
			int _threadNum;
			vector<Thread*> _threadsVec;  // 存放线程池里面的所有线程
			int _bufSize;
			Buffer _buf;  // 缓冲区用来存放任务，到时候线程池从里面取走一个任务执行
			bool _isExit;
	};
};
#endif
