 ///
 /// @file    queue.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 18:49:19
 ///
 
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<iostream>
using namespace std;
class queue
{
	public:
		queue(int size):_front(0),_real(0),_size(size),_parr(new int[_size]){}
		~queue()
		{
			delete []_parr;
		}
		bool empty()const;
		bool full()const;
		void push(int);
		void pop();
		int front()const;
		int real()const;
		int size()const;
	private:
		int _front;
		int _real;
		int _size;
		int* _parr;
};
#endif
