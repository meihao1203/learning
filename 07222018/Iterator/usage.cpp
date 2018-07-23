 ///
 /// @file    usage.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-22 21:02:08
 ///
 
#include<iostream>
#include"iterator.h"
using namespace std;
int main()
{
	Aggregate* pAggregate = new ConcreteAggregate(5);
	Iterator* pIterator = pAggregate->createIterator();
	for(;false==pIterator->isDone();pIterator->next())
	{
		cout<<pIterator->currentItem()<<" ";
	}
	cout<<endl<<endl;

	Iterator* it = pAggregate->begin();
	Iterator* itEnd = pAggregate->end();
	for(;(*it)!=(*itEnd);++(*it))
	{
		cout<<*(*it)<<" ";
	}
	cout<<endl;
	delete pAggregate;
	delete pIterator;
	pAggregate = NULL;
	pIterator = NULL;
	return 0;
}
