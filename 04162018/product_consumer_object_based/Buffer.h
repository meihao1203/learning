 ///
 /// @file    Buffer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 18:22:46
 ///
 
#ifndef __BUFFER_H__
#define __BUFFER_H__
#include<iostream>
#include"MutexLock.h"
#include"Condition.h"
#include<queue>
using namespace std;
namespace meihao
{
	typedef int DataType;
	class Buffer
	{
		public:
			Buffer(int);
			~Buffer();
			void push(DataType);
			DataType pop();
			bool full();
			bool empty();
		private:
			MutexLock _mutex;
			Condition _notFull;
			Condition _notEmpty;
			queue<DataType> _que;
			int _size;
	};
};
#endif
