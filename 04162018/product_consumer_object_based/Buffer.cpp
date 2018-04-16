 ///
 /// @file    Buffer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 18:36:07
 ///
 
#include<iostream>
#include"Buffer.h"
using namespace std;
namespace meihao
{
	Buffer::Buffer(int size):_mutex(),_notFull(_mutex),_notEmpty(_mutex),_size(size){}
	Buffer::~Buffer(){}
	bool Buffer::full()
	{
		return _size == _que.size();
	}
	bool Buffer::empty()
	{
		return _que.size() == 0;  // 这个地方脑子坏了，写成_size == 0;  导致后面pop等待作废
	}
	void Buffer::push(DataType value)
	{
		_mutex.lock();
		if(full())
		{
			_notFull.wait();  // 等待条件变量，队列没有满，唤醒
		}
		_que.push(value);
		cout<<"prodece a num "<<value<<endl;
		_notEmpty.notify();  // 有一个元素进队列，_notEmpty的条件变量满足
		_mutex.unlock();
	}
	DataType Buffer::pop()
	{
		_mutex.lock();
		if(empty())
		{
			_notEmpty.wait();  // 等待不空的条件变量_notEmpty满足
		}
		DataType tmp = _que.front();
		_que.pop();
		cout<<"consumer a num "<<tmp<<endl;
		_notFull.notify();
		_mutex.unlock();
		return tmp;
	}
};
