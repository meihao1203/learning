 ///
 /// @file    queueTest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-24 18:40:45
 ///
 
#include<iostream>
#include"queue.h"
using namespace std;
int main()
{
	queue q;
	q.push(10);
	q.push(12);
	q.push(14);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
}

