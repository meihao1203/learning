 ///
 /// @file    iterator.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 11:33:23
 ///
 
#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include<iostream>
using namespace std;
typedef int Data;
class Iterator;
class Aggregate
{
	public:
		Aggregate();
		virtual Iterator* createIterator() = 0;
		virtual int size() = 0;
		virtual Data& getItem(int idx) = 0;
		virtual Iterator* begin() = 0;
		virtual Iterator* end() = 0;
		virtual ~Aggregate();
};
class ConcreteAggregate:public Aggregate
{
	public:
		ConcreteAggregate(int);
		~ConcreteAggregate();
		Iterator* createIterator();
		int size();
		Data& getItem(int idx);
		Iterator* begin();
		Iterator* end();
	private:
		int _size;
		Data* _pData;
};
class Iterator
{
	public:
		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isDone() = 0;
		virtual Data& currentItem() = 0;
		virtual bool operator!=(Iterator&) = 0;
		virtual Data& operator*() = 0;
		virtual void operator++() = 0;
		virtual int index() = 0;
		virtual ~Iterator() = 0;
};
class ConcreteIterator:public Iterator
{
	public:
		ConcreteIterator(Aggregate*,int);
		void first();
		void next();
		bool isDone();
		Data& currentItem();
		bool operator!=(Iterator&);
		Data& operator*();
		void operator++();
		int index();
		~ConcreteIterator();
	private:
		Aggregate* _pAggregate;
		int _idx;
};
#endif
