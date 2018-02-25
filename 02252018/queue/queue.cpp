 ///
 /// @file    queue.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 19:16:23
 ///
 
#include"queue.h"
#include<iostream>
using namespace std;
bool queue::empty()const
{
	return _front == _real;   // _real指向队列下一个位置,队列浪费一个空间不用
}
bool queue::full()const
{
	return _front == ((_real+1)%_size);
}
void queue::push(int elem)
{
	if(!full())
	{
		_parr[_real++] = elem;
		_real %= _size;
	}
	else
	{
		cout<<"queue full!"<<endl;
	}
}
void queue::pop()
{
	if(!empty())
	{
		_front++;
		_front %= _size;
	}
	else
	{
		cout<<"queue empty!"<<endl;
	}
}
int queue::front()const
{
	if(!empty())
	{
		return _parr[_front];
	}
	else
	{
		cout<<"queue empty!"<<endl;
	}
}
int queue::real()const
{
	if(!empty())
	{
		return _parr[(_real-1+_size)%_size];
	}
	else
	{
		cout<<"queue empty!"<<endl;
	}
}
int queue::size()const
{
	return (_real-_front+_size)%_size;
}
