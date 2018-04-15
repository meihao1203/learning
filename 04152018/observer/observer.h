 ///
 /// @file    observer.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 19:37:48
 ///
 
#ifndef __OBSERVE_H__
#define __OBSERVE_H__
#include<iostream>
#include<list>
typedef int state;
using namespace std;
class Observer;
class Subject
{
	public:
		Subject():_subjectState(-1){}
		virtual ~Subject();  // 这边要删除开辟的空间
		void attach(Observer*);
		void detach(Observer*);
		void notify();
		virtual int getState();
		virtual void setState(state);
	protected:
		state _subjectState;
		list<Observer*> _observerList;
};
class ConcreteSubject:public Subject
{
	public:
		ConcreteSubject(){}
		int getState();
		void setState(state);
		virtual ~ConcreteSubject(){}
};
class Observer
{
	public:
		Observer():_obState(-1){}
		virtual void update(Subject*) = 0;
		virtual ~Observer(){}
	protected:
		state _obState;
};
class ConcreteObserver:public Observer
{
	public:
		ConcreteObserver(){}
		void update(Subject*);
		~ConcreteObserver(){}
};
#endif
