 ///
 /// @file    Threadpool.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 14:48:00
 ///
 
#include"Threadpool.h"
#include<iostream>
#include"Threadpoolthread.h"
#include<unistd.h>
using namespace std;
namespace meihao
{
	Threadpool::Threadpool(int threadNum,int bufSize):_threadNum(threadNum)
													  ,_bufSize(bufSize)
													  ,_buf(_bufSize)
													  ,_isExit(false)
	{
		_threadsVec.reserve(_threadNum);
	}
	void Threadpool::start()
	{
		for(int i=0;i<_threadNum;++i)
		{
			Thread* pthread = new Threadpoolthread(*this);  // 创建指定个数个线程
			_threadsVec.push_back(pthread);
		}
		for(auto& elem:_threadsVec)
		{
			elem->start();  // 创造的线程开始启动
		}
	}
	void Threadpool::stop()
	{
		if(!_isExit)
		{
			while(!_buf.empty())  // 如果缓冲池不空，也就是还有线程在执行
			{
				sleep(1);  // 等待所有线程执行完
			}
			// 线程全部执行完将会都挂在_buf里面的_notEmpty的条件变量上
			_buf.wakeupEmpty();  // 唤醒所有等待_notEmpty的线程
			// 这个函数设置flag = false; 所有等待在Buffer里面的pop函数
			// 里的线程将全部返回NULL
			_isExit = true;
			for(auto& elem:_threadsVec)
			{
				elem->join();   // 回收所有线程资源
				delete elem;
			}
		}
	}
	void Threadpool::addTask(Task* task)
	{
		_buf.push(task);
	}
	Task* Threadpool::getTask()
	{
		return _buf.pop();
	}
	void Threadpool::threadFunc()
	{
		while(!_isExit)
		{
			Task* task = getTask();
			if(task)
			{
				task->process();
			}
		}
	}
};
