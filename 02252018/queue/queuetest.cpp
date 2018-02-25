 ///
 /// @file    queuetest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-25 20:06:13
 ///
 
#include"queue.h"
#include<iostream>
using namespace std;
int main()
{
	queue q1(5);  // 浪费了一个空间，只能放4个
	cout<<q1.empty()<<endl;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	cout<<q1.size()<<endl;
	cout<<q1.full()<<endl;
	q1.pop();
	q1.push(4);
	cout<<q1.front()<<endl;
	cout<<q1.real()<<endl;
	q1.push(5);
	q1.push(6);
	q1.push(7);
}
//1
//3
//0
//2
//4
//queue full!
//queue full!
