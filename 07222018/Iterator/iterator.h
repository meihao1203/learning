 ///
 /// @file    Iterator.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-22 20:01:50
 ///
 
#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include<iostream>
using namespace std;
class Iterator;
class Aggregate
{
	public:
		Aggregate();
		virtual Iterator* createIterator() = 0;
		virtual int size() = 0;
		virtual int& getItem(int) = 0;
		virtual Iterator* begin() = 0;
		virtual Iterator* end() = 0;
		virtual ~Aggregate();
};
class ConcreteAggregate:public Aggregate
{
	public:
		ConcreteAggregate(int);
		~ConcreteAggregate();
		//实现抽象基类的纯虚函数
		Iterator* createIterator();
		int size();
		int& getItem(int);
		Iterator* begin();
		Iterator* end();
	private:
		int _size;
		int* _pData;
};
class Iterator
{
	public:
		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isDone() = 0;
		virtual int& currentItem() = 0;
		virtual int index() = 0;
		virtual bool operator!=(Iterator&) = 0;
		virtual bool operator==(Iterator&) = 0;
		virtual int& operator*() = 0;
		virtual void operator++() = 0;
};
class ConcreteIterator:public Iterator
{
	public:
		ConcreteIterator(Aggregate* ptr,int idx);
		void first();
		void next();
		bool isDone();
		int& currentItem();
		int index();
		bool operator!=(Iterator&);
		bool operator==(Iterator&);
		int& operator*() ;
		void operator++();
	private:
		Aggregate* _pAggregate;
		int _idx;
};
#endif
