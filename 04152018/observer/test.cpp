 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 09:28:00
 ///
 
#include<iostream>
#include"observer.h"
using namespace std;
int main()
{
	Observer* p1 = new ConcreteObserver;
	Observer* p2 = new ConcreteObserver;

	Subject* p = new ConcreteSubject;
	p->attach(p1);
	p->attach(p2);
	p->setState(5);
	p->notify();  // subject对象通知所有observer对象

	p->detach(p1);
	p->setState(10);
	p->notify();

	delete p;
	return 0;
}
//update state,Observer state now is 5
//update state,Observer state now is 5
//update state,Observer state now is 10
//~Subject()
