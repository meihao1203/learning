 ///
 /// @file    stack.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 14:49:52
 ///

#ifndef __STACK_H__
#define __STACK_H__
#include<iostream>
#include<string.h>
#define MAXSIZE 10
using namespace std;
class stack
{
	public:
		stack()
		{
			_tos = -1;
			//_stack[MAXSIZE] = {0}; //这里直接警告 
			memset(&_stack,0,sizeof(_stack));
			cout<<"stack()"<<endl;
		}
		~stack()
		{
			cout<<"~stack()"<<endl;
		}
		void push(int element)
		{
			if(_tos>=-1&&_tos<MAXSIZE-1)
			{
				_stack[++_tos] = element;
			}
			else
			{
				cout<<element<<" push fail!"<<endl;
			}
		}
		void pop()
		{
			if(_tos>-1&&_tos<MAXSIZE)
			{
				_tos--;
			}
			else
			{
				cout<<"pop fail!"<<endl;
			}
		}
		int top()
		{
			if(_tos>-1&&_tos<MAXSIZE)
			{
				return _stack[_tos];
			}
			else 
			{
				return -1; //error;
			}
		}
		bool empty()
		{
			if(-1==_tos)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		bool full()
		{
			if(MAXSIZE-1==_tos)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		int _tos;
		int _stack[MAXSIZE];
};
#endif
