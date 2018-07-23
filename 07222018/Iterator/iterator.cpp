 ///
 /// @file    Iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-22 20:32:50
 ///
 
#include<iostream>
#include"iterator.h"
using namespace std;
//ConcreteAggregate具体实现
Aggregate::Aggregate() 
{
}

Aggregate::~Aggregate()
{
}


ConcreteAggregate::ConcreteAggregate(int size):_size(size),_pData(new int[_size]) 
{
	for(int idx=0;idx!=_size;++idx)
		_pData[idx] = idx+1;
}
ConcreteAggregate::~ConcreteAggregate()
{
	delete []_pData;
	_pData = NULL;
}
Iterator* ConcreteAggregate::createIterator()
{
	return new ConcreteIterator(this,0);   
}
int ConcreteAggregate::size()
{
	return _size;
};
int& ConcreteAggregate::getItem(int idx)
{
	return _pData[idx];
}
Iterator* ConcreteAggregate::begin()
{
	return new ConcreteIterator(this,0);
}
Iterator* ConcreteAggregate::end()
{
	return new ConcreteIterator(this,_size);
}
//ConcreteIterator具体实现
ConcreteIterator::ConcreteIterator(Aggregate* ptr,int idx):_pAggregate(ptr)
										  ,_idx(idx)
{
}

void ConcreteIterator::first()
{
	_idx = 0;
}
void ConcreteIterator::next()
{
	++_idx;
}
bool ConcreteIterator::isDone()
{
	return _idx == _pAggregate->size();
}
int& ConcreteIterator::currentItem()
{
	return _pAggregate->getItem(_idx);
}
int ConcreteIterator::index()
{
	return _idx;
}
bool ConcreteIterator::operator!=(Iterator& rhs)
{
	return _idx != rhs.index();
}
bool ConcreteIterator::operator==(Iterator& rhs)
{
	return _idx == rhs.index();
}
int& ConcreteIterator::operator*()
{
	return this->currentItem();
}
void ConcreteIterator::operator++()
{
	++_idx;
}
