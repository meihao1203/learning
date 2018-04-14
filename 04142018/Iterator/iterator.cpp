 ///
 /// @file    iterator.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 12:01:37
 ///
 
#include<iostream>
#include"iterator.h"
using namespace std;
Aggregate::Aggregate()
{
	cout<<"Aggregate()"<<endl;
}
Aggregate::~Aggregate()
{
	cout<<"~Aggregate()"<<endl;
}
ConcreteAggregate::ConcreteAggregate(int size):_size(size)
{
	cout<<"ConcreteAggregate()"<<endl;
	_pData = new Data[_size];
	for(int i=0;i<_size;++i)
		_pData[i] = i+1;
}
ConcreteAggregate::~ConcreteAggregate()
{
	cout<<"~ConcreteAggregate()"<<endl;
	delete _pData;
}
Iterator* ConcreteAggregate::createIterator()
{
	return new ConcreteIterator(this,0);  // 生成组合类对象
}
int ConcreteAggregate::size()
{
	return _size;
}
Data& ConcreteAggregate::getItem(int idx)
{
	return _pData[idx];
}
Iterator* ConcreteAggregate::begin()
{
	return new ConcreteIterator(this,0);  // 生成组合类对象
}
Iterator* ConcreteAggregate::end()
{
	return new ConcreteIterator(this,_size);  // 返回一个指向_pData末尾的Iterator对象
}
/* ************************************* */
Iterator::~Iterator()
{
	cout<<"~Iterator()"<<endl;
}
ConcreteIterator::ConcreteIterator(Aggregate* pa,int idx):_pAggregate(pa),_idx(idx)
{
	cout<<"ConcreteIterator(Aggregate*,int)"<<endl;
}
ConcreteIterator::~ConcreteIterator()
{
	cout<<"~ConcreteIterator()"<<endl;
}
void ConcreteIterator::first()
{
	_idx = 0;  // 取Iterator类造出的对象的第一个元素
}
void ConcreteIterator::next()
{
	++_idx;
}
bool ConcreteIterator::isDone()
{
	return _idx == _pAggregate->size();
}
Data& ConcreteIterator::currentItem()
{
	return _pAggregate->getItem(_idx);
}
int ConcreteIterator::index()
{
	return _idx;  // 获取Iterator类对象的大小
}
bool ConcreteIterator::operator!=(Iterator& rhs)
{
	return _idx == rhs.index();
}
Data& ConcreteIterator::operator*()
{
	return currentItem();
}
void ConcreteIterator::operator++()
{
	++_idx;
}
