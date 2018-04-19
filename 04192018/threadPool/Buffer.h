 ///
 /// @file    Buffer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 10:30:46
 ///
 
#ifndef __BUFFER_H__
#define __BUFFER_H__
#include<iostream>
#include"MutexLock.h"
#include"Condition.h"
#include"Task.h"
#include<queue>
using namespace std;
namespace meihao
{
	typedef Task* DataType;
	class Buffer:private Noncopyable
	{
		public:
			Buffer(int);
			void push(DataType);
			DataType pop();
			void wakeupEmpty();  // 唤醒所有等待队列不为空的线程
			bool full();
			bool empty();
		private:
			MutexLock _mutex;
			Condition _notFull;
			Condition _notEmpty;
			int _queSize;
			queue<DataType> _que;
			bool _flag;
	};
};
#endif
