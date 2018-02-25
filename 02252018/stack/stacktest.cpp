 ///
 /// @file    stacktest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 18:36:56
 ///
 
#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	stack s(5);
	cout<<s.empty()<<endl;
	s.push(1);
	s.push(2);
	cout<<s.full()<<endl;
	cout<<s.size()<<endl;
	s.push(3);
	cout<<s.top()<<endl;
	s.pop();
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
}
//1
//0
//2
//3
//stack full!
