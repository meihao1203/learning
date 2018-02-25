 ///
 /// @file    stack.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 18:22:50
 ///
 
#include<iostream>
#include"stack.h"
using namespace std;
bool stack::empty()
{
	return _top == -1;
}
bool stack::full()
{
	return _top+1 == _size;
}
void stack::push(int elem)
{
	if(!full())
	{
		_parr[++_top] = elem;
	}
	else
	{
		cout<<"stack full!"<<endl;
	}
}
void stack::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
	{
		cout<<"stack empty!"<<endl;
	}
}
int stack::top()
{
	if(!empty())
	{
		return _parr[_top];
	}
	else
	{
		cout<<"stack empty!"<<endl;
	}
}
int stack::size()
{
	return _top+1;
}

