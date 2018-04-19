 ///
 /// @file    Task.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 10:29:03
 ///
 
#ifndef __TASK_H__
#define __TASK_H__
#include<iostream>
using namespace std;
namespace meihao
{
	class Task
	{
		public:
			virtual void process() = 0;  // 线程池里面的线程具体要做的任务
	};
};
#endif
