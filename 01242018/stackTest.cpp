 ///
 /// @file    stackTest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 16:26:07
 ///
 
#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	stack a;
	a.push(10);
	a.push(12);
	a.push(14);
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.top()<<endl;	//-1
	a.pop();	//pop fail!
}
//stack()
//14
//12
//10
//-1
//pop fail!
//~stack()
