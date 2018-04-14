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

}


