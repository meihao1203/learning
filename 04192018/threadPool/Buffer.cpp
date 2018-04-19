 ///
 /// @file    Buffer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-19 10:39:02
 ///
 
#include<iostream>
#include"Buffer.h"
using namespace std;
namespace meihao
{
	Buffer::Buffer(int size):_queSize(size)
							 ,_mutex()
							 ,_notFull(_mutex)
							 ,_notEmpty(_mutex)
							 ,_flag(true)   // 开始，标志位true，表示buffer正常运行
											// 后面线程池要结束的时候会修改为false
	{
	}
	bool Buffer::full()
	{
		return _queSize == _que.size();
	}
	bool Buffer::empty()
	{
		return _que.size() == 0;
	}
	void Buffer::push(DataType elem)
	{
		_mutex.lock();
		while(full())
		{
			_notFull.wait();  // 队列满，等待条件变量notFull满足
			// 放到while里面是为了防止异常唤醒,唤醒的时候再次确认是否真的条件满足
		}
		_que.push(elem);
		_notEmpty.notify();
		_mutex.unlock();
	}
	DataType Buffer::pop()
	{
		_mutex.lock();
		while(_flag&&empty())  // flag如果为false表示线程池等待回收线程stop线程池
		{
			_notEmpty.wait();
		}
		if(_flag)
		{
			DataType tmp = _que.front();
			_que.pop();
			_notFull.notify();
			_mutex.unlock();
			return tmp;
		}
		else
		{
			_mutex.unlock();
			return NULL;
		}
	}
	void Buffer::wakeupEmpty()
	{
		_flag = false;
		_notEmpty.notifyall();  // 线程池在要关闭的时候会等待所有线程执行完挂在等待条件变量notEmpty上
		//这个时候直接唤醒所有等待的线程
	}
};
