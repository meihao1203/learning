 ///
 /// @file    stack.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 17:09:29
 ///

#ifndef __STACK_H__
#define __STACK_H__
#include<iostream>
using namespace std;
class stack
{
	public:
		stack(int size=0):_size(size),_top(-1),_parr(new int[_size]){}
		~stack()
		{
			delete []_parr;
		}
		bool empty();
		bool full();
		void push(int);
		void pop();
		int top();
		int size();
	private:
		int _top;
		int _size;
		int* _parr;
};
#endif
