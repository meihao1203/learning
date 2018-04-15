 ///
 /// @file    observer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 19:55:21
 ///
 
#include"observer.h"
#include<algorithm>
#include<iterator>
#include<iostream>
using namespace std;
Subject::~Subject()
{
	cout<<"~Subject()"<<endl;
	list<Observer*>::iterator it = _observerList.begin();
	for(;it!=_observerList.end();++it)
	{
		delete *it;
	}
	_observerList.clear();
}
void Subject::attach(Observer* pObs)
{
	if(NULL!=pObs)
		_observerList.push_back(pObs);
}
void Subject::detach(Observer* pObs)
{
	list<Observer*>::iterator it = find(_observerList.begin(),_observerList.end(),pObs);
	if(it!=_observerList.end())
		_observerList.erase(it);
}
void Subject::notify()
{
	list<Observer*>::iterator it = _observerList.begin();
	for(;it!=_observerList.end();++it)
		//(*(*it)).update(this);  // 这里必须要两个括号，*(*it).update(this);  是错的
		(*it)->update(this);
//	for(auto& it:_observerList)   // 不知道为什么在这里不行啊，说是C++11不让声明没有类型的变量
//		it->update(this);
}
int Subject::getState()
{
	return _subjectState;
}
void Subject::setState(state newState)
{
	_subjectState = newState;
}
/*   ConcreteSubject   */
int ConcreteSubject::getState()
{
	return _subjectState;  // 要访问这个，基类就不能是私有成员,重新设置成保护
}
void ConcreteSubject::setState(state newState)
{
	_subjectState = newState;
}
/*   Observer   */
//直接传消息,叫推模式 string = ""
//传指针,    叫拉模式
void ConcreteObserver::update(Subject* pSub)
{
	if(_obState!=pSub->getState())
	{
		_obState = pSub->getState();
		cout<<"update state,Observer state now is "<<_obState<<endl;
	}
}
